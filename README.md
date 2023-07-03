## Fault_Simulation_and_Verification_for_Digital_Logic_Circuits
This repository contains C++ code for fault simulation in digital circuits using a simple logic gate model. The code aims to identify and evaluate faults in the circuit.

### Introduction
This code implements a fault simulation algorithm for digital circuits represented by logic gates. The circuit is modeled using a collection of gates, and the code simulates the propagation of faults through the circuit to determine the effect on the output.

### Files
* main.cpp: The main C++ file containing the implementation of the fault simulation algorithm.
* README.md: This file, providing an overview and instructions for running the code.

### Code Overview
The code is written in C++ and uses the **Standard Template Library (STL)** for data structures and algorithms.
The main components of the code are:

* 'Gate structure': Represents a logic gate in the circuit, with an output, two inputs, and a gate type (AND, OR, NOT, XOR).
* 'evaluateNode': Function to evaluate the output of a gate based on its inputs and gate type, considering the values of the input nodes.
* 'evaluateFaultAncestors': Function to evaluate the effects of a fault in the circuit by propagating it to the ancestor nodes.
* 'verifyFault': Function to verify a specific fault by setting the desired fault value and evaluating the circuit.

### Usage
To use this code, follow these steps:
1. Clone the repository to your local machine.
2. Open the main.cpp file in a C++ compatible compiler (e.g., GCC, Visual Studio, etc.).
3. Compile and run the code.
4. The output will display the values of nodes A, B, C, D, and Z, considering the SA0 fault on the specified faultNode.

### Example
For demonstration purposes, the main() function creates a simple circuit with gates representing the **logic: Z = (NOT F) XOR (A AND B)**. It simulates an **SA0 fault** on the **gate net_f** and verifies the impact on the output.

### Understanding the Circuit
The circuit is represented using a list of gates. Each gate has **an output, two inputs, and a gate type.**

The gate types are represented as follows: **'&' for AND, '|' for OR, '~' for NOT (inverter), and '^' for XOR.**
The output gate 'Z' represents the final output of the circuit.

### Simulating a Fault
In the main function, one can specify the fault to simulate by setting the faultNode and faultType variables. For example, to simulate a **SA0** (stuck-at-0) fault at node **"net_f,"** set the **faultNode** to **"net_f"** and **faultType** to **"SA0."**

The code will then evaluate the effects of this fault on the circuit, considering the propagation of the fault to the ancestor nodes.

### Expected Output
The program will display the expected values of nodes A, B, C, D, and Z after simulating the specified fault. The values will be in the format: **[A, B, C, D] = [value_A, value_B, value_C, value_D], Z = value_Z.**

### Conclusion
This code demonstrates a basic fault simulation algorithm for digital circuits. It can be extended to handle more complex circuits and fault types.

### Contributing
If you find any issues or have improvements to suggest, please create a pull request or raise an issue in the GitHub repository.

### Acknowledgments
The code is created by me, Anwesha Ghosh, inspired by the need for fault simulation in digital circuit design and verification.

Thank you for using this fault simulation code! If you have any questions or need further assistance, please don't hesitate to reach out. **Happy fault-simulation!!!**
