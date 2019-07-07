#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

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
#include <unordered_map>
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

class GraphApp : public Application {
public:

    void start(const std::string &algorithmName, const std::string &inputFilePath,
               const std::string &outputFilePath, unsigned short version = DEFAULT_VERSION) {

        auto alg = runTask("selecting algorithm", [&]() { return this->selectAlgorithm(algorithmName, version); });
        auto input = runTask("reading input file", &Application::readInputFile, inputFilePath);
        auto graph = runTask("creating graph", [&]() { return this->createGraph(input); });
        auto r = runTask("running algorithm", alg.execute, graph);
        runTask("print output", [&]() { this->printOutput(std::get<0>(r), std::get<1>(r)); });
    }

    const std::unordered_map<std::string, std::vector<Algorithm<std::tuple<double, Graph>(const Graph &graph)>>>
    getAlgorithmMap() {

        auto alg1 = {Algorithm<std::tuple<double, Graph>(const Graph &graph)>(graphAlgorithm),
                     Algorithm<std::tuple<double, Graph>(const Graph &graph)>(graphAlgorithm)};
        auto alg2 = {Algorithm<std::tuple<double, Graph>(const Graph &graph)>(graphAlgorithm),
                     Algorithm<std::tuple<double, Graph>(const Graph &graph)>(graphAlgorithm),
                     Algorithm<std::tuple<double, Graph>(const Graph &graph)>(graphAlgorithm)};

        return {{"kruskal", alg1},
                {"prim",    alg1}};
    }

    const Algorithm<std::tuple<double, Graph>(const Graph &graph)>
    selectAlgorithm(const std::string &algorithmName, unsigned short version) {
        return getAlgorithmMap().at(algorithmName)[version];
    }

    Graph createGraph(const std::string &input) {
        return Graph();
    }

    void printOutput(const double total, const Graph &mst) {}

    static std::tuple<double, Graph> graphAlgorithm(const Graph &graph) {
        return {0, Graph()};
    }

protected:

    static constexpr unsigned short DEFAULT_VERSION = std::numeric_limits<unsigned short>::max();
};


#endif //GRAPH_APPS_GRAPHAPP_H
