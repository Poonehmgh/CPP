# include "../inc/Serializer.hpp"
# include <cmath>
int main()
{
    Data    sample;
    sample.random = 30;
    sample.random_str = "hello";
    
    uintptr_t tmp = Serializer::serialize(&sample);
    Data *sample2 = Serializer::deserialize(tmp);
    std::cout << "Original pointer:\n" << YELLOW <<&sample;
    std::cout << RESET"\nAfter serializition:\n" << YELLOW <<sample2;
    std::cout << RESET"\the content:  " << sample2->random << "  " << sample2->random_str;
    return (0);
}