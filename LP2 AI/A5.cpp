#include <iostream>
#include <string>
#include <map>
#include <regex>

using namespace std;

class CustomerServiceChatbot
{
private:
    map<string, map<string, string>> context; // Map to store context
    string curr_item;

public:
    CustomerServiceChatbot()
    {
        // Initialize context with default values
        context["camera"] = {{"size", "36 MP"}, {"price", "$500"}, {"brand", "Canon"}, {"resolution", "5472x3648"}, {"warranty", "1 year"}};
        context["screen"] = {{"size", "6.5 inches"}, {"price", "$200"}, {"brand", "Samsung"}, {"resolution", "1080x2400"}, {"warranty", "2 years"}};
        context["sim"] = {{"size", "Nano-SIM"}, {"price", "$20"}, {"brand", "Apple"}, {"resolution", "N/A"}, {"warranty", "1 year"}};
        context["ram"] = {{"size", "8 GB"}, {"price", "$100"}, {"brand", "Corsair"}, {"resolution", "N/A"}, {"warranty", "Lifetime"}};
        context["memory"] = {{"size", "128 GB"}, {"price", "$50"}, {"brand", "SanDisk"}, {"resolution", "N/A"}, {"warranty", "5 years"}};
        context["battery"] = {{"size", "4000 mAh"}, {"price", "$80"}, {"brand", "Sony"}, {"resolution", "N/A"}, {"warranty", "6 months"}};
        context["current_context"] = {{"context", "None"}}; // Initialize current context to None
        curr_item = "";
    }

    void handleUserInput(const string &userInput)
    {
        // Regular expressions for matching queries
        regex sizeRegex("size of (\\w+)", regex_constants::icase);
        regex priceRegex("price of (\\w+)", regex_constants::icase);
        regex brandRegex("brand of (\\w+)", regex_constants::icase);
        regex resolutionRegex("resolution of (\\w+)", regex_constants::icase);
        regex warrantyRegex("warranty of (\\w+)", regex_constants::icase);
        regex hiRegex("hi", regex_constants::icase);
        regex exitRegex("exit", regex_constants::icase);

        smatch match;
         if (regex_search(userInput, match, hiRegex))
        {
            cout << "Chatbot: Hi there! How can I assist you today?" << endl;
            return;
        }

        // Check if user input is "exit"
        if (regex_search(userInput, match, exitRegex))
        {
            cout << "Chatbot: Goodbye! Have a great day!" << endl;
            exit(0);
        }
          // If no regex matches, use previous logic
        // Check if user input contains a keyword from context
        for (const auto &pair : context)
        {
            if (userInput.find(pair.first) != string::npos)
            {
                // Update current context
                curr_item = pair.first;
                context["current_context"] = pair.second;

                // Provide response based on context
                cout << "Chatbot: ";
                if (userInput == pair.first)
                { // Check if userInput is exactly equal to the keyword
                cout<<"Here"<<endl;
                    cout << "Size of " << pair.first << " is " << pair.second.at("size") << "." << endl;
                    cout << "Price of " << pair.first << " is " << pair.second.at("price") << "." << endl;
                    cout << "Brand of " << pair.first << " is " << pair.second.at("brand") << "." << endl;
                    cout << "Resolution of " << pair.first << " is " << pair.second.at("resolution") << "." << endl;
                    cout << "Warranty of " << pair.first << " is " << pair.second.at("warranty") << "." << endl;
                }
                else
                {
                    if (userInput.find("size") != string::npos)
                    {
                        cout << "Size of " << pair.first << " is " << pair.second.at("size") << "." << endl;
                    }
                    if (userInput.find("price") != string::npos)
                    {
                        cout << "Price of " << pair.first << " is " << pair.second.at("price") << "." << endl;
                    }
                    if (userInput.find("brand") != string::npos)
                    {
                        cout << "Brand of " << pair.first << " is " << pair.second.at("brand") << "." << endl;
                    }
                    if (userInput.find("resolution") != string::npos)
                    {
                        cout << "Resolution of " << pair.first << " is " << pair.second.at("resolution") << "." << endl;
                    }
                    if (userInput.find("warranty") != string::npos)
                    {
                        cout << "Warranty of " << pair.first << " is " << pair.second.at("warranty") << "." << endl;
                    }
                    if (userInput.find("size") == string::npos && userInput.find("price") == string::npos &&
                        userInput.find("brand") == string::npos && userInput.find("resolution") == string::npos &&
                        userInput.find("warranty") == string::npos)
                    {
                        cout << "I'm sorry, I didn't understand your query. Could you please rephrase?" << endl;
                    }
                }
                return;
            }
        }

        // Check if user input matches size query
        if (regex_search(userInput, match, sizeRegex))
        {
            string item = match[1].str(); // Extract item from regex match
            if (context.find(item) != context.end())
            {
                cout << "Chatbot: Size of " << item << " is " << context[item]["size"] << "." << endl;
                return;
            }
        }

        // Check if user input matches price query
        if (regex_search(userInput, match, priceRegex))
        {
            string item = match[1].str(); // Extract item from regex match
            if (context.find(item) != context.end())
            {
                cout << "Chatbot: Price of " << item << " is " << context[item]["price"] << "." << endl;
                return;
            }
        }

        // Check if user input matches brand query
        if (regex_search(userInput, match, brandRegex))
        {
            string item = match[1].str(); // Extract item from regex match
            if (context.find(item) != context.end())
            {
                cout << "Chatbot: Brand of " << item << " is " << context[item]["brand"] << "." << endl;
                return;
            }
        }

        // Check if user input matches resolution query
        if (regex_search(userInput, match, resolutionRegex))
        {
            string item = match[1].str(); // Extract item from regex match
            if (context.find(item) != context.end())
            {
                cout << "Chatbot: Resolution of " << item << " is " << context[item]["resolution"] << "." << endl;
                return;
            }
        }

        // Check if user input matches warranty query
        if (regex_search(userInput, match, warrantyRegex))
        {
            string item = match[1].str(); // Extract item from regex match
            if (context.find(item) != context.end())
            {
                cout << "Chatbot: Warranty of " << item << " is " << context[item]["warranty"] << "." << endl;
                return;
            }
        }


        // If no context matches, use previously stored context
        if (context["current_context"]["context"] != "None")
        {
            cout<<context["current_context"]["context"]<<"    ";
            cout << "Chatbot: ";
            if (userInput.find("size") != string::npos)
            {
               
                cout << "Size of " << curr_item<< " is "
                     << context["current_context"].at("size") << "." << endl;
            }
            else if (userInput.find("price") != string::npos)
            {
                cout << "Price of " << curr_item<< " is "
                     << context["current_context"].at("price") << "." << endl; // Access price directly from the context
            }
            else if (userInput.find("brand") != string::npos)
            {
                cout << "Brand of " << curr_item<< " is "
                     << context["current_context"].at("brand") << "." << endl;
            }
            else if (userInput.find("resolution") != string::npos)
            {
                cout << "Resolution of " << curr_item<< " is "
                     << context["current_context"].at("resolution") << "." << endl;
            }
            else if (userInput.find("warranty") != string::npos)
            {
                cout << "Warranty of " << curr_item << " is "
                     << context["current_context"].at("warranty") << "." << endl;
            }
            else
            {
                cout << "I'm sorry, I didn't understand your query. Could you please rephrase?" << endl;
            }
        }
        else
        {
            cout << "Chatbot: I'm sorry, I didn't understand your query. Could you please provide more context?" << endl;
        }
    }
};


int main()
{
    CustomerServiceChatbot chatbot;

    cout << "Welcome to Customer Service Chatbot" << endl;
    cout << "You can start chatting. Type 'bye' to exit." << endl;

    string userInput;
    while (true)
    {
        cout << "User: ";
        getline(cin, userInput);

        if (userInput == "bye")
        {
            cout << "Chatbot: Goodbye! Have a great day!" << endl;
            break;
        }

        chatbot.handleUserInput(userInput);
    }

    return 0;
}
