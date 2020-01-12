    // Declare second integer, double, and String variables.
    int j = 0;
    double e = 0.0;
    std::string t;

    // Read and save an integer, double, and String to your variables.
    std::cin >> j;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
    std::cin >> e;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, t);
    // Print the sum of both integer variables on a new line.
    std::cout << i + j << "\n";
    // Print the sum of the double variables on a new line.
    std::cout<<std::fixed;
    std::cout<<std::setprecision(1);
    std::cout <<  e +d << "\n";
    // Concatenate and print the String variables on a new line
    std::cout <<s+ t << "\n";
    // The 's' variable above should be printed first.
    
