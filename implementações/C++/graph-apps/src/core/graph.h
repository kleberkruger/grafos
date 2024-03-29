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

#ifndef GRAPH_APPS_GRAPH_H
#define GRAPH_APPS_GRAPH_H


#include <vector>

struct Edge {

    Edge(unsigned int start, unsigned int end, double weight) : start(start), end(end), weight(weight) {}

    unsigned int start;
    unsigned int end;
    double weight;
};

class Graph {
public:

    explicit Graph(unsigned int n, unsigned long m = 0) : verticesSize(n) {
        if (m > 0) edges.reserve(m);
    }

    void insertEdge(unsigned int v1, unsigned int v2, double w) {
        edges.emplace_back(v1, v2, w);
    }

    unsigned int getVerticesSize() const {
        return verticesSize;
    }

    const std::vector<Edge> &getEdges() const {
        return edges;
    }

private:

    unsigned int verticesSize;
    std::vector<Edge> edges;
};


#endif //GRAPH_APPS_GRAPH_H
