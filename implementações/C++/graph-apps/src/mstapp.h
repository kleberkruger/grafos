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

#ifndef GRAPH_APPS_MSTAPP_H
#define GRAPH_APPS_MSTAPP_H


#include "core/graphapp.h"
#include "core/graph.h"

using MSTAlg = Algorithm<std::tuple<double, Graph>(const Graph &)>;

class MSTApp : public GraphApp<MSTAlg> {
public:

    void start(const std::string &algorithmName, const std::string &inputFilePath,
               const std::string &outputFilePath, unsigned short version) override {

        auto alg = runTask("selecting algorithm", [&]() { return this->selectAlgorithm(algorithmName, version); });
        auto input = runTask("reading input file", &Application::readInputFile, inputFilePath);
        auto graph = runTask("creating graph", [&]() { return createGraph(input); });
        auto r = runTask("running algorithm", alg.execute, graph);
        runTask("print output", [&]() { printOutput(std::get<0>(r), std::get<1>(r)); });
    }

    const std::unordered_map<std::string, std::vector<MSTAlg>> getAlgorithmMap() override {
        return {{"kruskal", {MSTAlg(graphAlgorithm), MSTAlg(graphAlgorithm)}},
                {"prim",    {MSTAlg(graphAlgorithm), MSTAlg(graphAlgorithm)}}};
    }

private:

    static Graph createGraph(const std::string &input) {
        char *token;
        unsigned int n = strtol(input.c_str(), &token, 10);
        unsigned int m = strtol(token, &token, 10);

        Graph graph(n, m);

        for (int i = 0; i < m; i++) {
            unsigned int v1 = strtol(token, &token, 10);
            unsigned int v2 = strtol(token, &token, 10);
            double w = strtod(token, &token);
            graph.insertEdge(v1, v2, w);
        }

        return graph;
    }

    static void printOutput(const double total, const Graph &mst) {
        printOutputFile("dataset/t1/out_kruger.txt", "resposta");
    }

    static std::tuple<double, Graph> graphAlgorithm(const Graph &graph) {
        return {0, Graph()};
    }

};


#endif //GRAPH_APPS_MSTAPP_H
