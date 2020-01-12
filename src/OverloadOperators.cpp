//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator +( Complex x, Complex y){
    Complex result;
    result.a = x.a + y.a;
    result.b = x.b + y.b;
    return result;
}

std::ostream& operator<< ( std::ostream& out, Complex& x){
    out<< x.a<<"+i" << x.b;
    return out;
}