
template<class T>
class AggrigateT{

public:

    T m_objTest;

    AggrigateT() { std::cout << "Construction object of AggrigateT" << std::endl; }
    ~AggrigateT() { std::cout << "Destroying object of AggrigateT" << std::endl; }

};