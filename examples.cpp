//1
class Counter {
    int count = 0;
public :
    void increment () { ++ count ; }
    int get () const { return count ; }
};
void inspect ( const Counter & c ) {
    c.increment();
std :: cout << c . get () ;
}

//2
void reset (int x ) {
    x = 0;
}
int main () {
    int a = 42;
    reset ( a ) ;
    std :: cout << a ;
}

//3
std :: vector <int > v = {1 , 2 , 3};
for ( auto it = v . begin () ; it != v . end () ; ++ it ) {
    if (* it == 2) {
        v.push_back (4) ;
    }
}

//4
int* make_array () {
    int data [5] = {1 , 2 , 3 , 4 , 5};
    return data ;
}
void use () {
    int* p = make_array();
    std::cout << p[0];
}

//5
class Printer {
    std::string prefix ;
public:
    static void error ( const std::string & msg ) {
        std::cerr << prefix << " Error : " << msg ;
    }
};

//6
class Animal {
public :
    ~ Animal () {}
};
class Dog : public Animal {
    char * name ;
public :
    Dog () : name (new char [20]) {}
    ~ Dog () { delete [] name ; }
};
void test () {
    Animal * p = new Dog () ;
    delete p ;
}
