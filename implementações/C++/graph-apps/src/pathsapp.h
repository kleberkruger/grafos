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

#ifndef GRAPH_APPS_PATHSAPP_H
#define GRAPH_APPS_PATHSAPP_H


#include "core/graphapp.h"
#include "core/graph.h"

using PathUAlg = Algorithm<std::tuple<std::vector<double>, std::vector<unsigned int>>(const Graph &, unsigned int)>;

class PathsUniqueApp : public GraphApp<PathUAlg> {
public:

    void start(const std::string &algorithmName, const std::string &inputFilePath,
               const std::string &outputFilePath, unsigned short version) override {

    }

    virtual const std::unordered_map<std::string, std::vector<PathUAlg>> getAlgorithmMap() override {
        return {{"bellman-ford", {PathUAlg(graphAlgorithm), PathUAlg(graphAlgorithm)}},
                {"dijkstra",     {PathUAlg(graphAlgorithm), PathUAlg(graphAlgorithm)}}};
    }

private:

    static std::tuple<Graph, unsigned int> createGraph(const std::string &input) {
        char *token;
        unsigned int n = strtol(input.c_str(), &token, 10);
        unsigned int m = strtol(token, &token, 10);
        unsigned int s = strtol(token, &token, 10);

        Graph graph(n, m);

        for (int i = 0; i < m; i++) {
            unsigned int v1 = strtol(token, &token, 10);
            unsigned int v2 = strtol(token, &token, 10);
            double w = strtod(token, &token);
            graph.insertEdge(v1, v2, w);
        }

        return {graph, s};
    }

    static void printOutput(const std::vector<double> &dist, const std::vector<unsigned int> &pred) {}

    static std::tuple<std::vector<double>, std::vector<unsigned int>>
    graphAlgorithm(const Graph &graph, unsigned int source) {
        return {std::vector<double>(), std::vector<unsigned int>()};
    }
};

template<typename T>
using matrix = std::vector<std::vector<T>>;

using PathMAlg = Algorithm<std::tuple<matrix<double>, matrix<unsigned int>>(const Graph &)>;

class PathsMultipleApp : public GraphApp<PathMAlg> {
public:


    void start(const std::string &algorithmName, const std::string &inputFilePath,
               const std::string &outputFilePath, unsigned short version) override {

    }

    const std::unordered_map<std::string, std::vector<PathMAlg>> getAlgorithmMap() override {
        return {{"floyd-warshall", {PathMAlg(graphAlgorithm), PathMAlg(graphAlgorithm)}},
                {"johnson",        {PathMAlg(graphAlgorithm), PathMAlg(graphAlgorithm)}}};
    }

private:

    static Graph createGraph(const std::string &input) {
        char *token;
        unsigned int n = strtol(input.c_str(), &token, 10);
        unsigned int m = strtol(token, &token, 10);
        strtol(token, &token, 10); // source is not necessary

        Graph graph(n, m);

        for (int i = 0; i < m; i++) {
            unsigned int v1 = strtol(token, &token, 10);
            unsigned int v2 = strtol(token, &token, 10);
            double w = strtod(token, &token);
            graph.insertEdge(v1, v2, w);
        }

        return graph;
    }

    static void printOutput(const matrix<double> &dist, const matrix<unsigned int> &pred) {}

    static std::tuple<matrix<double>, matrix<unsigned int>> graphAlgorithm(const Graph &graph) {
        return {matrix<double>(), matrix<unsigned int>()};
    }
};


#endif //GRAPH_APPS_PATHSAPP_H
