#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// QUEST holds the questions along with their weight and key improvement area
unordered_map<string, pair<int, string>> QUEST = {
    {"Does the employee meet deadlines consistently?", {10, "Punctuality"}},
    {"Is the employee proactive in taking on new tasks or responsibilities?", {4, "Responsibility"}},
    {"Does the employee communicate effectively with team members and superiors?", {6, "Communication skills"}},
    {"Does the employee demonstrate a strong understanding of their role and responsibilities?", {3, "Understanding of role"}},
    {"Does the employee seek feedback to improve their performance?", {4, "Feedback solicitation"}},
    {"Does the employee work well in a team environment?", {6, "Teamwork"}},
    {"Does the employee demonstrate strong problem-solving skills?", {7, "Problem-solving"}},
    {"Does the employee show initiative in solving problems or improving processes?", {4, "Initiative"}},
    {"Does the employee demonstrate a commitment to the organization's goals and values?", {8, "Commitment to goals and values"}},
    {"Does the employee adapt well to change?", {5, "Adaptability"}},
    {"Does the employee take ownership of their work and responsibilities?", {8, "Ownership"}},
    {"Does the employee demonstrate leadership qualities?", {6, "Leadership"}},
    {"Does the employee contribute innovative ideas or solutions?", {7, "Innovation"}},
    {"Does the employee maintain a positive attitude in challenging situations?", {6, "Positive attitude"}},
    {"Does the employee demonstrate a willingness to learn and grow?", {3, "Learning and growth"}},
    {"Does the employee handle constructive criticism well?", {4, "Constructive criticism handling"}},
    {"Does the employee adhere to company policies and procedures?", {5, "Adherence to policies and procedures"}}
};

// EXPERT contains descriptions for different performance levels
unordered_map<string, string> EXPERT = {
    {"Excellent", "Based on the evaluation, the employee's performance is excellent. They consistently exceed expectations and demonstrate exceptional skills and qualities."},
    {"Good", "Based on the evaluation, the employee's performance is good. They meet or exceed expectations in most areas and demonstrate strong skills and qualities."},
    {"Fair", "Based on the evaluation, the employee's performance is fair. They meet expectations in some areas but may need improvement in others."},
    {"Poor", "Based on the evaluation, the employee's performance is poor. They do not meet expectations in several areas and may require significant improvement."},
    {"Unsatisfactory", "Based on the evaluation, the employee's performance is unsatisfactory. They do not meet expectations and require immediate improvement."}
};

// THRESHOLD defines the minimum scores for different performance levels
unordered_map<string, int> THRESHOLD = {
    {"Excellent", 90},
    {"Good", 70},
    {"Fair", 50},
    {"Poor", 30},
    {"Unsatisfactory", 0}
};

// Display list of questions and responses from the user
void displayQuestionsAndResponse(vector<string> response) {
    int idx = 0;
    cout << "Employee Evaluation Questions" << endl;
    cout<<left  << setw(90) << "Questions" << setw(10) << "Response" << endl;
    for (auto q : QUEST) {
        cout << left << setw(90) << q.first << setw(10) << response[idx++] << endl;
    }
}

// Display feedback based on the responses
void displayFeedback(vector<vector<string>> feedback) {
    cout << "Low - Major Improvement Needed: ";
    for(auto it : feedback[0]) cout << it << " , ";
    cout << endl;

    cout << "Medium - Satisfactory but Improvement Needed: ";
    for(auto it : feedback[1]) cout << it << " , ";
    cout << endl;

    cout << "High - Well done - Improvement Needed: ";
    for(auto it : feedback[2]) cout << it << " , ";
    cout << endl;
}

// Perform employee evaluation
void employeeEvaluation() {
    int totalScore = 0;
    int maxScore = 0;
    vector<string> customerResponse;
    vector<vector<string>> feedback(3);

    cout << "Employee Evaluation System" << endl;
    cout << "Please answer the following questions with 'low', 'average', or 'high'." << endl;

    for (auto q : QUEST) {
        string response;
        cout << "Question: " << q.first << endl;
        cout << "Enter 'low', 'average', or 'high': ";
        cout << "> ";
        cin >> response;
        customerResponse.push_back(response);

        maxScore += q.second.first + 3; // Update maximum possible score

        if (response == "low") {
            feedback[0].push_back(q.second.second);
            totalScore += q.second.first - 3; // Adjust score for low response
        } else if (response == "average") {
            feedback[1].push_back(q.second.second);
            totalScore += q.second.first; // No adjustment for average response
        } else if (response == "high") {
            feedback[2].push_back(q.second.second);
            totalScore += q.second.first + 3; // Adjust score for high response
        } else {
            cout << "Invalid response. Please enter 'low', 'average', or 'high'." << endl;
            continue; // Continue to next question without updating score
        }
    }

    // Display questions and responses
    displayQuestionsAndResponse(customerResponse);

    // Display total score, maximum possible score, and percentage score
    cout << "Total Score: " << totalScore << endl;
    cout << "Maximum Possible Score: " << maxScore << endl;
    cout << "Percentage Score: " << (totalScore * 100) / maxScore << "%" << endl;

    // Display employee evaluation based on total score
    cout << "Employee Evaluation: ";
    if (totalScore >= THRESHOLD["Excellent"]) {
        cout << EXPERT["Excellent"] << endl;
    } else if (totalScore >= THRESHOLD["Good"]) {
        cout << EXPERT["Good"] << endl;
    } else if (totalScore >= THRESHOLD["Fair"]) {
        cout << EXPERT["Fair"] << endl;
    } else if (totalScore >= THRESHOLD["Poor"]) {
        cout << EXPERT["Poor"] << endl;
    } else {
        cout << EXPERT["Unsatisfactory"] << endl;
    }

    // Display feedback based on the responses
    displayFeedback(feedback);
}

int main() {
    employeeEvaluation();
    return 0;
}
