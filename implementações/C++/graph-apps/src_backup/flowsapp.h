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

using FIn = std::tuple<const Graph &, unsigned int, unsigned int>;
using FOut = std::tuple<Graph, unsigned long>;
using FAlg = Algorithm<FOut(const Graph &, unsigned int, unsigned int)>;

class FlowsApp : public GraphApp<FIn, FOut> {
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
        char *token;
        unsigned int n = strtol(input.c_str(), &token, 10);
        unsigned int m = strtol(token, &token, 10);
        unsigned int s = strtol(token, &token, 10);
        unsigned int t = strtol(token, &token, 10);

        Graph graph(n, m);

        for (int i = 0; i < m; i++) {
            unsigned int v1 = strtol(token, &token, 10);
            unsigned int v2 = strtol(token, &token, 10);
            unsigned int c = strtol(token, &token, 10);
            graph.insertEdge(v1, v2, c);
        }

        return {graph, s, t};
    }

    static FOut graphAlgorithm(const Graph &graph, unsigned int source, unsigned int target) {
        return {Graph(), 0};
    }

    void printOutput(const Graph &graph, const unsigned long &total) override {}

    const std::unordered_map<std::string, std::vector<FAlg>> getAlgorithmMap() override {
        return {{"ford-fulkerson", {FAlg(graphAlgorithm), FAlg(graphAlgorithm)}},
                {"edmonds-karp",   {FAlg(graphAlgorithm), FAlg(graphAlgorithm)}},
                {"dinics",         {FAlg(graphAlgorithm), FAlg(graphAlgorithm)}}};
    }
};


#endif //GRAPH_APPS_FLOWSAPP_H
