//#include <functional>
//#include <iostream>
//#include <tuple>
//
//using std::cout;
//using std::endl;
//using std::tuple;
//
//template<typename...Args>
//void show_types(Args...) {
//    cout << __PRETTY_FUNCTION__ << endl;
//}
//
//template<typename... Param>
//struct ParamGroup;
//
//template<typename...>
//struct App;
//
///**
// * T1, T2
// *
// * @tparam T1
// * @tparam T2
// */
//template<typename T1, typename T2>
//struct App<T1, T2>
//        : public App<ParamGroup<T1>, ParamGroup<T2>> {
//
////    virtual void do_something(T1 group1, T2 group2) {
////        show_types(group1);
////        show_types(group2);
////    }
//};
//
///**
// * T1, tuple<T2>
// *
// * @tparam ParamGroupT
// * @tparam T1
// * @tparam TypeGroup2
// */
//template<
//        template<typename...> class ParamGroupT,
//        typename T1,
//        typename...TypeGroup2
//>
//struct App<T1, ParamGroupT<TypeGroup2...>>
//        : public App<ParamGroup<T1>, ParamGroup<TypeGroup2...>> {
//
////    virtual void do_something(T1 group1, TypeGroup2...group2) {
////        show_types(group1);
////        show_types(group2...);
////    }
//};
//
///**
// * tuple<T1>, T2
// *
// * @tparam MyTypeGroupingT
// * @tparam TypeGroup1
// * @tparam T2
// */
//template<
//        template<typename...> class MyTypeGroupingT,
//        typename...TypeGroup1,
//        typename T2
//>
//struct App<MyTypeGroupingT<TypeGroup1...>, T2>
//        : public App<ParamGroup<TypeGroup1...>, ParamGroup<T2>> {
//
////    virtual void do_something(TypeGroup1...group1, T2 group2) {
////        show_types(group1...);
////        show_types(group2);
////    }
//};
//
///**
// * tuple<T1>, tuple<T2>
// *
// * @tparam MyTypeGroupingT
// * @tparam TypeGroup1
// * @tparam TypeGroup2
// */
//template<
//        template<typename...> class MyTypeGroupingT,
//        typename...TypeGroup1,
//        typename...TypeGroup2
//>
//struct App<MyTypeGroupingT<TypeGroup1...>, MyTypeGroupingT<TypeGroup2...>> {
//
//    virtual void do_something(TypeGroup1...group1, TypeGroup2...group2) {
//        show_types(group1...);
//        show_types(group2...);
//    }
//
//    virtual void test1(TypeGroup1...group1, TypeGroup2...group2) = 0;
//
//////    virtual std::tuple<TypeGroup1...> test2(TypeGroup2...group2) = 0;
////    template<typename R>
////    virtual R test2(TypeGroup2...group2) = 0;
////
//////    virtual TypeGroup1 test2(TypeGroup2...group2) = 0;
//////    virtual TypeGroup2... test2(TypeGroup1...group1) = 0;
//};
//
//class Herdada : public App<int,
//        std::tuple<float, bool>> {
////        MyTypeGrouping<float, bool>> {
//public:
//
//    virtual void test1(int i, float f, bool b) override {
//        std::cout << "sem tuplas: " << i << ", " << f << ", " << b << std::endl;
//    }
//
////    virtual void test1(int i, std::tuple<float, bool> t) override { // este override falha
////        std::cout << "usando tuplas: " << i << ", " << std::get<0>(t) << ", " << std::get<1>(t) << std::endl;
////    }
//
////    virtual std::tuple<int> test2(float f, bool b) {
////        return {8};
////    }
////
//////    virtual int test2(float f, bool b) override {
//////        return 9;
//////    }
//};
//
////class Herdada2 : public App<void,
////        std::tuple<float, bool>> {
//////        MyTypeGrouping<float, bool>> {
////public:
////
////    virtual void test1(void i, float f, bool b) override {
////        std::cout << "sem tuplas: " << i << ", " << f << ", " << b << std::endl;
////    }
////
////    virtual void test2(float f, bool b) override {}
////};
//
//template <typename... T>
//auto funcao(T... args) -> decltype(auto){
//    std::cout << "hehehe" << std::endl;
//    return 1;
//}
//
//int main(int argc, char **argv) {
//
////    {
////        DoesSomething<int, float> d;
////        d.do_something(1, 2.0);
////    }
////
////    {
////        DoesSomething<int, MyTypeGrouping<double, bool>> d;
////        d.do_something(1, 3.0, true);
////    }
////
////    {
////        DoesSomething<MyTypeGrouping<int, float>, bool> d;
////        d.do_something(1, 2.0, true);
////    }
////
////    {
////        DoesSomething<MyTypeGrouping<int, float>, MyTypeGrouping<double, bool>> d;
////        d.do_something(1, 2.0, 3.0, true);
////    }
////
////    {
////        DoesSomething<tuple<int>, tuple<float, int, int, double, bool>> d;
////        d.do_something(1, 2.0, 3, 4, 3.0, true);
////    }
//
//    Herdada h;
//    h.test1(7, 5.6, true);
//
//    int a = funcao(5);
//    std::cout << a << std::endl;
//}