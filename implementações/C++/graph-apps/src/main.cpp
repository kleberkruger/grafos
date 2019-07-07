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

#include "mstapp.h"
#include "flowsapp.h"

int main(int argc, char *argv[]) {
    MSTApp().start(argv[1], argv[3], argv[4], 0);
    FlowsApp().start(argv[1], argv[3], argv[4], 0);

//    // one, one
//    GraphApp2<int, bool>().do_something(1, true);
//    // one, group
//    GraphApp2<int, TypeGroup<double, bool>>().do_something(1, 3.0, true);
//    // group, one
//    GraphApp2<TypeGroup<double, bool>, int>().do_something(3.0, true, 1);
//    // group, group
//    GraphApp2<TypeGroup<int, float>, TypeGroup<double, bool>>().do_something(1, 2.0, 3.0, true);
//    // group, group
//    GraphApp2<std::tuple<int>, std::tuple<float, int, int, double, bool>>().do_something(1, 2.0, 3, 4, 3.0, true);

    return EXIT_SUCCESS;
}
