#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> values;

struct Gate
{
    string output;
    string input1;
    string input2;
    string type;

    Gate(string output, string inp1, string inp2, string type)
    {
        this->output = output;
        this->input1 = inp1;
        this->input2 = inp2;
        this->type = type;
    }
};

void evaluateFaultAncestors(vector<Gate> &gates, string node, bool desiredValue){

    if(node == "A" || node == "B" || node== "C" || node == "D"){
        return;
    }

    for(auto gate: gates){
        if(gate.output == node){

            if (gate.type == "~")
            {
                values[gate.input1] = !desiredValue;
                evaluateFaultAncestors(gates, gate.input1, !desiredValue);

            }
            else if (gate.type == "&")
            {
                values[gate.input1] = desiredValue?1:0;
                values[gate.input2] = desiredValue?1:0;
                evaluateFaultAncestors(gates, gate.input1, values[gate.input1]&values[gate.input2]);
                evaluateFaultAncestors(gates, gate.input2, values[gate.input1]&values[gate.input2]);
            }
            else if (gate.type == "|")
            {
                values[gate.input1] = desiredValue?0:0;
                values[gate.input2] = desiredValue?1:0;
                evaluateFaultAncestors(gates, gate.input1, values[gate.input1]&values[gate.input2]);
                evaluateFaultAncestors(gates, gate.input2, values[gate.input1]&values[gate.input2]);
            }
            else if (gate.type == "^")
            {
                values[gate.input1] = desiredValue?1:0;
                values[gate.input2] = desiredValue?0:0;
                evaluateFaultAncestors(gates, gate.input1, values[gate.input1]&values[gate.input2]);
                evaluateFaultAncestors(gates, gate.input2, values[gate.input1]&values[gate.input2]);
            }

            break;
        }
    }
}



int evaluateNode(vector<Gate> &gates, string node)
{

    if (values.find(node) != values.end())
    {
        return values[node];
    }

    for (const auto &gate : gates)
    {
        if (gate.output == node)
        {
            int input1Value = evaluateNode(gates, gate.input1);
            int input2Value = evaluateNode(gates, gate.input2);

            if (gate.type == "~")
            {
                values[node] = (input1Value == 0) ? 1 : 0;
            }
            else if (gate.type == "&")
            {
                values[node] = (input1Value == 1 && input2Value == 1) ? 1 : 0;
            }
            else if (gate.type == "|")
            {
                values[node] = (input1Value == 1 || input2Value == 1) ? 1 : 0;
            }
            else if (gate.type == "^")
            {
                values[node] = (input1Value != input2Value) ? 1 : 0;
            }

            break;
        }
    }

    return values[node];
}



void printExpectedOutput()
{
    string output = "[A,B,C,D] = [" + to_string(values["A"]) + ", "
         + to_string(values["B"]) + ", " + to_string(values["C"]) + ", "
         + to_string(values["D"]) + "],Z = "+  to_string(values["Z"]);

    cout<<output<<endl;
}



void verifyFault(vector<Gate> &gates, string &faultNode, string &faultType)
{
    values.clear();
    values[faultNode] = (faultType == "SA0") ? 0 : 1;
    bool desiredFaultValue = !values[faultNode];

    //Evalute the fault ancestors
    evaluateFaultAncestors(gates, faultNode, desiredFaultValue);

    // Evaluate the fault node
    evaluateNode(gates, "Z");

    // print values
    printExpectedOutput();
}


int main()
{
    vector<Gate> gates;
    gates.push_back(Gate("net_e", "A", "B", "&"));
    gates.push_back(Gate("net_f", "C", "D", "|"));
    gates.push_back(Gate("net_g", "net_f", "", "~"));
    gates.push_back(Gate("Z", "net_g", "net_e", "^"));

    string faultNode = "net_f";
    string faultType = "SA0";

    verifyFault(gates, faultNode, faultType);

    return 0;
}