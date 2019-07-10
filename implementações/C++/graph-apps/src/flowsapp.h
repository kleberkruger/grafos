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

#ifndef GRAPH_APPS_FLOWSAPP_H
#define GRAPH_APPS_FLOWSAPP_H


#include <tuple>
#include "core/graphapp.h"
#include "core/graph.h"

class FlowsApp : public GraphApp<
        std::tuple<const Graph &, unsigned int, unsigned int>, std::tuple<Graph, unsigned long>> {
public:

//    void start(const std::string &algorithmName, const std::string &inputFilePath,
//               const std::string &outputFilePath, unsigned short version) override {
//
//        auto alg = runTask("selecting algorithm", [&]() { return this->selectAlgorithm(algorithmName, version); });
//        auto text = runTask("reading input file", &Application::readInputFile, inputFilePath);
//        auto input = runTask("creating graph", [&]() { return createGraph(text); });
//        auto r = runTask("running algorithm", alg.execute, std::get<0>(input), std::get<1>(input), std::get<2>(input));
//        runTask("print output", [&]() { printOutput(std::get<0>(r), std::get<1>(r)); });
//    }

    std::tuple<Graph, unsigned int, unsigned int> createGraph(const std::string &input) override {
        return {Graph(), 0, 0};
    }

    static std::tuple<Graph, unsigned long>
    graphAlgorithm(const Graph &graph, unsigned int source, unsigned int target) {
        return {Graph(), 0};
    }

    void printOutput(const Graph &graph, const unsigned long &total) override {}

    const std::unordered_map<std::string, std::vector<Algorithm<std::tuple<Graph, unsigned long>(
            const Graph &, unsigned int, unsigned int)>>> getAlgorithmMap() override {

        auto alg1 = {
                Algorithm<std::tuple<Graph, unsigned long>(const Graph &, unsigned int, unsigned int)>(graphAlgorithm),
                Algorithm<std::tuple<Graph, unsigned long>(const Graph &, unsigned int, unsigned int)>(graphAlgorithm)};
        auto alg2 = {
                Algorithm<std::tuple<Graph, unsigned long>(const Graph &, unsigned int, unsigned int)>(graphAlgorithm),
                Algorithm<std::tuple<Graph, unsigned long>(const Graph &, unsigned int, unsigned int)>(graphAlgorithm)};

        return {{"kruskal", alg1},
                {"prim", alg2}};
    }
};


#endif //GRAPH_APPS_FLOWSAPP_H
