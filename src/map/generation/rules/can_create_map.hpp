#ifndef CAN_CREATE_MAP_HPP
#define CAN_CREATE_MAP_HPP

namespace Map
{
    // copied from https://gist.github.com/fenbf/d2cd670704b82e2ce7fd
    template <typename T>
    class CanCreateMap
    {
    private:
        typedef char YesType[1];
        typedef char NoType[2];

        template <typename C> static YesType& test( decltype(&C::createMap) ) ;
        template <typename C> static NoType& test(...);


    public:
        enum { value = sizeof(test<T>(0)) == sizeof(YesType) };
    };
} // namespace Map

#endif