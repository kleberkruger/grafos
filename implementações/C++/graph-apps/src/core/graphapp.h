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

template<class Alg>
class GraphApp : public Application {
public:

    virtual const std::unordered_map<std::string, std::vector<Alg>> getAlgorithmMap() = 0;

    virtual void start(const std::string &algorithmName, const std::string &inputFilePath,
                       const std::string &outputFilePath, unsigned short version) = 0;

protected:

    const Alg selectAlgorithm(const std::string &algorithmName, unsigned short version) {

        auto &map = getAlgorithmMap();
        auto it = map.find(algorithmName);

        if (it == map.end()) {
            throw std::invalid_argument("Incorrect algorithm name");
        } else if (version >= (*it).second.size()) {
            throw std::invalid_argument("Incorrect version to " + algorithmName);
        }

        return it->second[version];
    }
};


#endif //GRAPH_APPS_GRAPHAPP_H
