#include <type_traits>
#include <functional>
#include <iostream>
#include <tuple>

using std::cout;
using std::endl;
using std::tuple;

template<typename...Args>
void show_types(Args...) {
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename... Param>
struct ParamGroup;

template<typename...>
struct App;

/**
 * T1, T2
 *
 * @tparam T1
 * @tparam T2
 */
template<typename T1, typename T2>
struct App<T1, T2> : public App<ParamGroup<T1>, ParamGroup<T2>> {
};

/**
 * T1, tuple<T2>
 *
 * @tparam ParamGroupT
 * @tparam T1
 * @tparam TypeGroup2
 */
template<
        template<typename...> class ParamGroupT,
        typename T1,
        typename...TypeGroup2
>
struct App<T1, ParamGroupT<TypeGroup2...>> : public App<ParamGroup<T1>, ParamGroup<TypeGroup2...>> {
};

/**
 * tuple<T1>, T2
 *
 * @tparam MyTypeGroupingT
 * @tparam TypeGroup1
 * @tparam T2
 */
template<
        template<typename...> class MyTypeGroupingT,
        typename...TypeGroup1,
        typename T2
>
struct App<MyTypeGroupingT<TypeGroup1...>, T2> : public App<ParamGroup<TypeGroup1...>, ParamGroup<T2>> {
};

/**
 * tuple<T1>, tuple<T2>
 *
 * @tparam MyTypeGroupingT
 * @tparam TypeGroup1
 * @tparam TypeGroup2
 */
template<
        template<typename...> class MyTypeGroupingT,
        typename...TypeGroup1,
        typename...TypeGroup2
>
struct App<MyTypeGroupingT<TypeGroup1...>, MyTypeGroupingT<TypeGroup2...>> {

    virtual void do_something(TypeGroup1...group1, TypeGroup2...group2) {
        show_types(group1...);
        show_types(group2...);
    }

    virtual void test1(TypeGroup1...group1, TypeGroup2...group2) = 0;

//    auto retType1() {
//        if constexpr (((std::tuple_size_v<std::tuple<TypeGroup1...>>) > 1)) {
//            return std::tuple<TypeGroup1...>();
//        } else {
//            return std::get<0>(std::tuple<TypeGroup1...>());
//        }
//    }

//    template<typename... T>
//    auto ReturnType() {
//        if constexpr (((std::tuple_size_v<std::tuple<T...>>) > 1)) {
//            return std::tuple<TypeGroup1...>();
//        } else {
//            return std::get<0>(std::tuple<TypeGroup1...>());
//        }
//    }
//
//    virtual auto test2(TypeGroup2...) -> decltype(ReturnType<TypeGroup1...>()) = 0;

//    typename std::enable_if<((std::tuple_size_v<std::tuple<TypeGroup1...>>) == 1), TypeGroup1...>::type
//    virtual test3(TypeGroup2...) = 0;

//    typename std::enable_if<((std::tuple_size_v<std::tuple<TypeGroup1...>>) > 1), std::tuple<TypeGroup1...>>::type
//    virtual test3(TypeGroup2...) = 0;
};

///**
// * tuple<T1>, tuple<T2>, R1, R2
// *
// * @tparam MyTypeGroupingT
// * @tparam ReturnType1
// * @tparam ReturnType2
// * @tparam TypeGroup1
// * @tparam TypeGroup2
// */
//template<
//        template<typename...> class MyTypeGroupingT,
//        typename...TypeGroup1,
//        typename...TypeGroup2,
//        typename ReturnType1,
//        typename ReturnType2
//>
//struct App<MyTypeGroupingT<TypeGroup1...>, ReturnType1,
//        MyTypeGroupingT<TypeGroup2...>, ReturnType2> {
//
//    virtual void do_something(TypeGroup1...group1, TypeGroup2...group2) {
//        show_types(group1...);
//        show_types(group2...);
//    }
//
//    virtual void test1(TypeGroup1...group1, TypeGroup2...group2) = 0;
//
//    virtual ReturnType1 test2(TypeGroup2...group2) = 0;
//};

class buceta {

};

class Derivada1 : public App<buceta, std::tuple<float, bool>> {
public:

    virtual void test1(buceta i, float f, bool b) override {
        std::cout << "sem tuplas: " << ", " << f << ", " << b << std::endl;
    }

    virtual buceta test2(float f, bool b) {
        return buceta();
    }

//    virtual int test3(float f, bool b) override {
//        return 8;
//    }
};

class Derivada2 : public App<std::tuple<bool, buceta, int>, std::tuple<float, bool>> {
public:

    virtual void test1(bool bola, buceta d, int i, float f, bool b) override {
        std::cout << "sem tuplas: " << i << ", " << f << ", " << b << std::endl;
    }

    virtual std::tuple<bool, buceta, int> test2(float f, bool b) {
        return {true, buceta(), 3};
    }

//    virtual std::tuple<int, bool> test3(float f, bool b) override {
//        return {6, true};
//    }
};


int main(int argc, char **argv) {

    Derivada1 d1;
    Derivada2 d2;
//    d.do_something(7, 5.6, true);
//    d.test1(7, 5.6, true);
//    d.test2(5.6, true);

    bool b = ((std::tuple_size_v<std::tuple<int, bool>>) > 1);

//    {
//        DoesSomething<int, float> d;
//        d.do_something(1, 2.0);
//    }
//
//    {
//        DoesSomething<int, MyTypeGrouping<double, bool>> d;
//        d.do_something(1, 3.0, true);
//    }
//
//    {
//        DoesSomething<MyTypeGrouping<int, float>, bool> d;
//        d.do_something(1, 2.0, true);
//    }
//
//    {
//        DoesSomething<MyTypeGrouping<int, float>, MyTypeGrouping<double, bool>> d;
//        d.do_something(1, 2.0, 3.0, true);
//    }
//
//    {
//        DoesSomething<tuple<int>, tuple<float, int, int, double, bool>> d;
//        d.do_something(1, 2.0, 3, 4, 3.0, true);
//    }
}
