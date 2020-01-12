		/* Enter your code here. */
        try {
            std::cout << Server::compute(A,B)<<"\n";
        }
        catch( std::bad_alloc & x){
            std::cout << "Not enough memory\n";
        }
        catch( std::exception & ex){
            std::cout<< "Exception: " << ex.what() <<"\n";
        }
        catch(...){
            std::cout<<"Other Exception\n";
        }