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

#include <iostream>
#include <variant>
#include "mstapp.h"
#include "pathsapp.h"
#include "flowsapp.h"

class MainApp {
public:

    using variant_apps = std::variant<MSTApp, PathsUniqueApp, PathsMultipleApp, FlowsApp>;

    void start(const std::string &algorithmName, const std::string &inputFilePath,
               const std::string &outputFilePath, unsigned short version) {

        auto it = getAlgorithmsMap().find(algorithmName);

        if (it == getAlgorithmsMap().end()) {
            std::string errorMsg("Incorrect algorithm name\n");
            errorMsg.append(getAlgorithmList());

            throw std::invalid_argument(errorMsg);
        }

        std::visit([&](auto app) { app.start(algorithmName, inputFilePath, outputFilePath, version); }, it->second);
    }

    static std::string getAlgorithmList() {
        std::string str("The list of [ algorithms | version ] is:\n");
        for (auto &app : getApps()) {
            std::visit([&](auto app) {
                for (auto &item : app.getAlgorithmMap()) {
                    str.append("- ").append("\"" + item.first + "\"")
                            .append("\t| versions: 0..").append(std::to_string(item.second.size())).append("\n");
                }
            }, app);
        }
        return str;
    }

private:

//    static const inline std::vector<variant_apps> apps{MSTApp(), PathsUniqueApp(), PathsMultipleApp(), FlowsApp()};

    static const inline std::vector<variant_apps> &getApps() {
        static const std::vector<variant_apps> apps{MSTApp(), PathsUniqueApp(), PathsMultipleApp(), FlowsApp()};
        return apps;
    };

//    static const inline std::unordered_map<std::string, variant_apps> algorithmsMap{
//            {"kruskal",        apps[0]},
//            {"prim",           apps[0]},
//            {"bellman-ford",   apps[1]},
//            {"dijkstra",       apps[1]},
//            {"floyd-warshall", apps[2]},
//            {"johnson",        apps[2]},
//            {"ford-fulkerson", apps[3]},
//            {"edmonds-karp",   apps[3]},
//            {"dinics",         apps[3]},
//    };

    static const inline std::unordered_map<std::string, variant_apps> &getAlgorithmsMap() {
        auto &apps = getApps();
        static const std::unordered_map<std::string, variant_apps> algorithmsMap{
                {"kruskal",        apps[0]},
                {"prim",           apps[0]},
                {"bellman-ford",   apps[1]},
                {"dijkstra",       apps[1]},
                {"floyd-warshall", apps[2]},
                {"johnson",        apps[2]},
                {"ford-fulkerson", apps[3]},
                {"edmonds-karp",   apps[3]},
                {"dinics",         apps[3]},
        };
        return algorithmsMap;
    }
};

int main(int argc, char *argv[]) {

    MainApp mainApp;

    if (argc != 4 && argc != 5) {
        std::string errorMsg = "Invalid argument format\n"
                               "Run with the arguments: <algorithm>* <version> <filepath-in>* <filepath-out>*\n"
                               "- Argument <version> is optional\n\n";

        errorMsg.append(MainApp::getAlgorithmList());

        throw std::invalid_argument(errorMsg);
    }

    short hasVersion = argc == 5 ? 1 : 0;
    short version = hasVersion ? std::strtol(argv[2], nullptr, 10) : -1;

    mainApp.start(argv[1], argv[2 + hasVersion], argv[3 + hasVersion], version);

    return EXIT_SUCCESS;
}
