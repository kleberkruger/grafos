//struct base {
//    virtual ~base() {} /* ... */
//};
//
//template<typename T, typename E = void>
//struct A;
//
//template<typename T> // implementation for types derived from base
//struct A<T, typename std::enable_if<std::is_base_of<base, T>::value, void>::type> {
//    static void identify() { std::cout << "T is a derived class of base\n"; }
//};
//
//// if required
//template<typename T> //  implementation for types which are not derived from base
//struct A<T, typename std::enable_if<!std::is_base_of<base, T>::value, void>::type> {
//    static void identify() { std::cout << "T is not derived from base\n"; }
//};

//template<class _Fp>
//class myfunction; // undefined
//
//template<class _Rp, class ..._ArgTypes>
//class myfunction<_Rp(_ArgTypes...)>
//        : public std::__function::__maybe_derive_from_unary_function<_Rp(_ArgTypes...)>,
//          public std::__function::__maybe_derive_from_binary_function<_Rp(_ArgTypes...)> {
//};

#include <functional>
#include <string>
#include <iostream>
#include <tuple>

template<typename...ArgsT>
void show_types(ArgsT...) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename InputTypes, typename OutputTypes>
class AppBase {
public:
    void do_something(InputTypes input, OutputTypes output) {
        show_types(input);
        show_types(output);
    }
};

template<typename... TypesT>
struct TypeGroup;

template<typename...>
class GraphApp2;

template<
        typename InputTypes,
        typename OutputTypes
>
class GraphApp2<InputTypes, OutputTypes> : public AppBase<InputTypes, OutputTypes> {
};

template<
        template<typename...> class TypeGroupT,
        typename InputTypes,
        typename...OutputTypes
>
class GraphApp2<InputTypes, TypeGroupT<OutputTypes...>> : public AppBase<InputTypes, TypeGroupT<OutputTypes...>> {
public:

    void do_something(InputTypes input, OutputTypes... output) {
        show_types(input);
        show_types(output...);
    }
};

template<
        template<typename...> class TypeGroupT,
        typename...InputTypes,
        typename OutputTypes
>
class GraphApp2<TypeGroupT<InputTypes...>, OutputTypes> : public AppBase<InputTypes..., OutputTypes>{
public:

    void do_something(InputTypes...input, OutputTypes output) {
        show_types(input...);
        show_types(output);
    }
};

template<
        template<typename...> class TypeGroupT,
        typename...InputTypes,
        typename...OutputTypes
>
class GraphApp2<TypeGroupT<InputTypes...>, TypeGroupT<OutputTypes...>> :
        public AppBase<TypeGroup<InputTypes...>, TypeGroup<OutputTypes...>>{

public:

    void do_something(InputTypes...input, OutputTypes...output) {
        show_types(input...);
        show_types(output...);
    }
};

int main() {

    // one, one
    GraphApp2<int, bool>().do_something(1, true);
    // one, group
    GraphApp2<int, TypeGroup<double, bool>>().do_something(1, 3.0, true);
    GraphApp2<int, TypeGroup<double, bool>>().do_something(1, 3.0, true);
    // group, one
    GraphApp2<TypeGroup<double, bool>, int>().do_something(3.0, true, 1);
    // group, group
    GraphApp2<TypeGroup<int, float>, TypeGroup<double, bool>>().do_something(1, 2.0, 3.0, true);
    // group, group
    GraphApp2<std::tuple<int>, std::tuple<float, int, int, double, bool>>().do_something(1, 2.0, 3, 4, 3.0, true);

    return 0;
}