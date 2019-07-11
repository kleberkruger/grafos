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

using PUIn = std::tuple<const Graph &, unsigned int>;
using PUOut = std::tuple<std::vector<double>, std::vector<unsigned int>>;
using PUAlg = Algorithm<PUOut(const Graph &, unsigned int)>;

class PathsUniqueApp : public GraphApp<PUIn, PUOut> {
public:

    static PUOut graphAlgorithm(const Graph &graph, unsigned int source) {
        return {std::vector<double>(), std::vector<unsigned int>()};
    }

    virtual std::tuple<Graph, unsigned int> createGraph(const std::string &input) override {
        return {Graph(), 0};
    }

    virtual const std::unordered_map<std::string, std::vector<PUAlg>> getAlgorithmMap() override {
        return {{"bellman-ford", {PUAlg(graphAlgorithm), PUAlg(graphAlgorithm)}},
                {"dijkstra",     {PUAlg(graphAlgorithm), PUAlg(graphAlgorithm)}}};
    }

    virtual void printOutput(const std::vector<double> &dist, const std::vector<unsigned int> &pred) override {}
};

template<typename T>
using matrix = std::vector<std::vector<T>>;

using PMIn = const Graph &;
using PMOut = std::tuple<matrix<double>, matrix<unsigned int>>;
using PMAlg = Algorithm<PMOut(const Graph &)>;

class PathsMultipleApp : public GraphApp<PMIn, PMOut> {
public:

    static PMOut graphAlgorithm(const Graph &graph) {
        return {matrix<double>(), matrix<unsigned int>()};
    }

    virtual Graph createGraph(const std::string &input) override {
        return Graph();
    }

    const std::unordered_map<std::string, std::vector<PMAlg>> getAlgorithmMap() override {
        return {{"floyd-warshall", {PMAlg(graphAlgorithm), PMAlg(graphAlgorithm)}},
                {"johnson",        {PMAlg(graphAlgorithm), PMAlg(graphAlgorithm)}}};
    }

    virtual void printOutput(const matrix<double> &dist, const matrix<unsigned int> &pred) override {}
};


#endif //GRAPH_APPS_PATHSAPP_H
