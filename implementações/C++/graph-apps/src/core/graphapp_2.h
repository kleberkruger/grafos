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

template<class F>
class GraphApp : public Application {
public:

    virtual void start(const std::string &algorithmName, const std::string &inputFilePath,
                       const std::string &outputFilePath, unsigned short version = DEFAULT_VERSION) = 0;

    virtual const std::unordered_map<std::string, std::vector<Algorithm<F>>> getAlgorithmMap() = 0;

    const Algorithm<F> selectAlgorithm(const std::string &algorithmName, unsigned short version) {
        auto &map = getAlgorithmMap();
        auto it = map.find(algorithmName);

        if (it == map.end()) {
            throw std::invalid_argument("Incorrect algorithm name");
        } else if (version >= (*it).second.size()) {
            throw std::invalid_argument("Incorrect version to " + algorithmName);
        }

        return map.at(algorithmName)[version];
    }

protected:

    static constexpr unsigned short DEFAULT_VERSION = std::numeric_limits<unsigned short>::max();
};


template<typename...ArgsT>
void show_types(ArgsT...) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename... TypesT>
struct TypeGroup;

template<typename...>
class GraphApp2;

//template<
//        typename InputTypes,
//        typename OutputTypes
//>
//class GraphApp2<InputTypes, OutputTypes> : public Application {
//public:
//
//    void do_something(InputTypes input, OutputTypes output) {
//        show_types(input);
//        show_types(output);
//    }
//
//    using GraphAlgorithm = Algorithm<OutputTypes>(InputTypes);
//
//    virtual void start(const std::string &algorithmName, const std::string &inputFilePath,
//                       const std::string &outputFilePath, unsigned short version = DEFAULT_VERSION) = 0;
//
//    virtual const std::unordered_map<std::string, std::vector<GraphAlgorithm>> getAlgorithmMap() {};
//
//    const GraphAlgorithm selectAlgorithm(const std::string &algorithmName, unsigned short version) {
//        auto &map = getAlgorithmMap();
//        auto it = map.find(algorithmName);
//
//        if (it == map.end()) {
//            throw std::invalid_argument("Incorrect algorithm name");
//        } else if (version >= (*it).second.size()) {
//            throw std::invalid_argument("Incorrect version to " + algorithmName);
//        }
//
//        return map.at(algorithmName)[version];
//    }
//
//protected:
//
//    static constexpr unsigned short DEFAULT_VERSION = std::numeric_limits<unsigned short>::max();
//};

template<
        template<typename...> class TypeGroupT,
        typename InputTypes,
        typename...OutputTypes
>
class GraphApp2<InputTypes, TypeGroupT<OutputTypes...>> : public Application {
public:

    void do_something(InputTypes input, OutputTypes... output) {
        show_types(input);
        show_types(output...);
    }

    using GraphAlgorithm = Algorithm<TypeGroupT<OutputTypes...>(InputTypes)>;

    virtual void start(const std::string &algorithmName, const std::string &inputFilePath,
                       const std::string &outputFilePath, unsigned short version = DEFAULT_VERSION) = 0;

    virtual const std::unordered_map<std::string, std::vector<GraphAlgorithm>> getAlgorithmMap() {};

    const GraphAlgorithm selectAlgorithm(const std::string &algorithmName, unsigned short version) {
        auto &map = getAlgorithmMap();
        auto it = map.find(algorithmName);

        if (it == map.end()) {
            throw std::invalid_argument("Incorrect algorithm name");
        } else if (version >= (*it).second.size()) {
            throw std::invalid_argument("Incorrect version to " + algorithmName);
        }

        return map.at(algorithmName)[version];
    }

protected:

    static constexpr unsigned short DEFAULT_VERSION = std::numeric_limits<unsigned short>::max();
};

template<
        template<typename...> class TypeGroupT,
        typename...InputTypes,
        typename OutputTypes
>
class GraphApp2<TypeGroupT<InputTypes...>, OutputTypes> : public Application {
public:

    void do_something(InputTypes...input, OutputTypes output) {
        show_types(input...);
        show_types(output);
    }

    using GraphAlgorithm = Algorithm<OutputTypes(InputTypes...)>;

    virtual void start(const std::string &algorithmName, const std::string &inputFilePath,
                       const std::string &outputFilePath, unsigned short version = DEFAULT_VERSION) = 0;

    virtual const std::unordered_map<std::string, std::vector<GraphAlgorithm>> getAlgorithmMap() {};

    const GraphAlgorithm selectAlgorithm(const std::string &algorithmName, unsigned short version) {
        auto &map = getAlgorithmMap();
        auto it = map.find(algorithmName);

        if (it == map.end()) {
            throw std::invalid_argument("Incorrect algorithm name");
        } else if (version >= (*it).second.size()) {
            throw std::invalid_argument("Incorrect version to " + algorithmName);
        }

        return map.at(algorithmName)[version];
    }

protected:

    static constexpr unsigned short DEFAULT_VERSION = std::numeric_limits<unsigned short>::max();
};

template<
        template<typename...> class TypeGroupT,
        typename...InputTypes,
        typename...OutputTypes
>
class GraphApp2<TypeGroupT<InputTypes...>, TypeGroupT<OutputTypes...>> : public Application {
public:

    using GraphAlgorithm = Algorithm<TypeGroupT<OutputTypes...>(InputTypes...)>;

    void do_something(InputTypes...input, OutputTypes...output) {
        show_types(input...);
        show_types(output...);
    }

    void start(const std::string &algorithmName, const std::string &inputFilePath,
               const std::string &outputFilePath, unsigned short version = DEFAULT_VERSION) {

    }

    virtual const std::unordered_map<std::string, std::vector<GraphAlgorithm>> getAlgorithmMap() {};

    const GraphAlgorithm selectAlgorithm(const std::string &algorithmName, unsigned short version) {
        auto &map = getAlgorithmMap();
        auto it = map.find(algorithmName);

        if (it == map.end()) {
            throw std::invalid_argument("Incorrect algorithm name");
        } else if (version >= (*it).second.size()) {
            throw std::invalid_argument("Incorrect version to " + algorithmName);
        }

        return map.at(algorithmName)[version];
    }

protected:

    static constexpr unsigned short DEFAULT_VERSION = std::numeric_limits<unsigned short>::max();
};


#endif //GRAPH_APPS_GRAPHAPP_H
