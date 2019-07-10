/*
 * MIT License
 *
 * Copyright (c) 2019 Kleber Kruger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef GRAPH_APPS_GRAPHAPP_H
#define GRAPH_APPS_GRAPHAPP_H


#include <functional>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#include "application.h"
#include "graph.h"

template<class F>
struct Algorithm {

    std::function<F> execute;
    std::string name;

    explicit Algorithm(std::function<F> func, std::string name = "") : execute(std::move(func)),
                                                                       name(std::move(name)) {}
};

template<typename...Args>
void show_types(Args...) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename... Types>
struct TypeGroup;

template<typename...>
class GraphApp;

/**
 * T1, T2
 *
 * @tparam InputTypes
 * @tparam OutputTypes
 */
template<typename InputTypes, typename OutputTypes>
class GraphApp<InputTypes, OutputTypes>
        : public GraphApp<TypeGroup<InputTypes>, TypeGroup<OutputTypes>> {
};

/**
 * T1, std::tuple<T2>
 *
 * @tparam TypeGroupT
 * @tparam InputTypes
 * @tparam OutputTypes
 */
template<template<typename...> class TypeGroupT, typename InputTypes, typename...OutputTypes>
class GraphApp<InputTypes, TypeGroupT<OutputTypes...>>
        : public GraphApp<TypeGroup<InputTypes>, TypeGroup<OutputTypes...>> {
};

/**
 * std::tuple<T1>, T2
 *
 * @tparam TypeGroupT
 * @tparam InputTypes
 * @tparam OutputTypes
 */
template<template<typename...> class TypeGroupT, typename...InputTypes, typename OutputTypes>
class GraphApp<TypeGroupT<InputTypes...>, OutputTypes>
        : public GraphApp<TypeGroup<InputTypes...>, TypeGroup<OutputTypes>> {
};

/**
 * std::tuple<T1>, std::tuple<T2>
 *
 * @tparam TypeGroupT
 * @tparam InputTypes
 * @tparam OutputTypes
 */
template<template<typename...> class TypeGroupT, typename...InputTypes, typename...OutputTypes>
class GraphApp<TypeGroupT<InputTypes...>, TypeGroupT<OutputTypes...>> : public Application {
private:

    template<typename... T>
    static auto ReturnType() {
        if constexpr (((std::tuple_size_v<std::tuple<std::decay_t<T>...>>) > 1)) {
            return std::tuple<std::decay_t<T>...>();
        } else {
            return std::get<0>(std::tuple<std::decay_t<T>...>());
        }
    }

public:

    using GraphAlgorithm = Algorithm<decltype(ReturnType<OutputTypes...>())(InputTypes...)>;

    static inline auto execute(const GraphAlgorithm &algorithm, const InputTypes &... input) {
        std::cout << "estou na tua mãe" << std::endl;
        show_types(input...);

        return algorithm.execute(input...);
    }

    static inline auto execute(const GraphAlgorithm &algorithm, const std::tuple<InputTypes...> &input) {
        std::cout << "estou na tupla" << std::endl;
        show_types(input);

        return std::apply(algorithm.execute, input);
    }

    static inline auto print(const GraphAlgorithm &algorithm, const InputTypes &... input) {
        std::cout << "estou na tua mãe" << std::endl;
        show_types(input...);

        return algorithm.execute(input...);
    }

    static inline auto print(const GraphAlgorithm &algorithm, const std::tuple<InputTypes...> &input) {
        std::cout << "estou na tupla" << std::endl;
        show_types(input);

        return std::apply(algorithm.execute, input);
    }

    virtual void start(const std::string &algorithmName, const std::string &inputFilePath,
                       const std::string &outputFilePath, unsigned short version) {

        auto alg = runTask("selecting algorithm", [&]() { return this->selectAlgorithm(algorithmName, version); });
        auto text = runTask("reading input file", &Application::readInputFile, inputFilePath);
        auto input = runTask("creating graph", [&]() { return createGraph(text); });

//        auto output = runTask("running algorithm", execute, alg, input);
        auto output = execute(alg, input);

//        runTask("print output", [&]() { printOutput(output); });
    }

    virtual const std::unordered_map<std::string, std::vector<GraphAlgorithm>> getAlgorithmMap() = 0;

    const GraphAlgorithm selectAlgorithm(const std::string &algorithmName, unsigned short version) {

        auto &map = getAlgorithmMap();
        auto it = map.find(algorithmName);

        if (it == map.end()) {
            throw std::invalid_argument("Incorrect algorithm name");
        } else if (version >= (*it).second.size()) {
            throw std::invalid_argument("Incorrect version to " + algorithmName);
        }

        return (*it).second[version];
    }

    virtual auto createGraph(const std::string &text) -> decltype(ReturnType<InputTypes...>()) = 0;

    virtual void printOutput(const OutputTypes &...) = 0;
};


#endif //GRAPH_APPS_GRAPHAPP_H
