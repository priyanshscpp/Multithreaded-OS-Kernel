# CPU Scheduling Algorithms Project Documentation

## Table of Contents

- [Introduction](#introduction)
- [Implemented Algorithms](#implemented-algorithms)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Input Format](#input-format)
- [Usage](#usage)
- [Testing](#testing)
- [Algorithm Details](#algorithm-details)
- [Extending the Project](#extending-the-project)
- [References](#references)

---

## Introduction

This project implements various CPU scheduling algorithms in C++. It is designed to simulate and analyze the behavior of different scheduling strategies, providing both trace and statistical outputs. The project is suitable for educational purposes, operating systems coursework, and performance analysis.

---

## Implemented Algorithms

1. **FCFS (First Come First Serve)**
2. **RR (Round Robin)**
3. **SPN (Shortest Process Next)**
4. **SRT (Shortest Remaining Time)**
5. **HRRN (Highest Response Ratio Next)**
6. **FB-1 (Feedback, all queues q=1)**
7. **FB-2i (Feedback, q=2^i)**
8. **Aging**

---

## Project Structure

```
CPU-Scheduling-Algorithms-main/
├── src/                # Source code for algorithms and main program
├── include/            # Header files
├── test/               # Unit tests (Google Test)
├── docs/               # Documentation
├── makefile            # Build instructions
├── README.md           # Project overview and quick start
└── run.sh              # Shell script to build and run the project
```

---

## Installation

1. **Clone the repository:**
   ```sh
   git clone <repository-url>
   cd CPU-Scheduling-Algorithms-main
   ```

2. **Install dependencies:**
   ```sh
   sudo apt-get update
   sudo apt-get install -y g++ make libgtest-dev cmake
   ```

3. **Build the project:**
   ```sh
   make
   ```

---

## Input Format

- **Line 1:** `"trace"` or `"stats"` (output mode)
- **Line 2:** Comma-separated list of scheduling policies and parameters (e.g., `1,2-4,8-1`)
- **Line 3:** Integer specifying the last instant for simulation
- **Line 4:** Integer specifying the number of processes
- **Line 5+:** Process descriptions (one per line)

### Process Description

- **Algorithms 1-7:**
  ```
  <ProcessName>,<ArrivalTime>,<ServiceTime>
  ```
- **Algorithm 8 (Aging):**
  ```
  <ProcessName>,<ArrivalTime>,<Priority>
  ```

**Note:**  
Processes must be sorted by arrival time. If two processes have the same arrival time, the one with the lower priority arrives first.

---

## Usage

1. **Compile the project:**
   ```sh
   make
   ```

2. **Run the main executable:**
   ```sh
   ./main < input.txt
   ```

   Replace `input.txt` with your input file following the [Input Format](#input-format).

---

## Testing

Unit tests are provided using Google Test.

- **Build and run tests:**
  ```sh
  make test
  ./test/hello_gtest
  ```

- **Automated testing:**  
  GitHub Actions is configured to run tests on every push and pull request.

---

## Algorithm Details

### 1. FCFS (First Come First Serve)
- Non-preemptive.
- Processes are executed in the order they arrive.

### 2. RR (Round Robin)
- Preemptive.
- Each process gets a fixed time quantum in a cyclic order.

### 3. SPN (Shortest Process Next)
- Non-preemptive.
- Selects the process with the shortest service time.

### 4. SRT (Shortest Remaining Time)
- Preemptive version of SPN.
- Always runs the process with the shortest remaining time.

### 5. HRRN (Highest Response Ratio Next)
- Non-preemptive.
- Chooses the process with the highest response ratio.

### 6. FB-1 (Feedback, q=1)
- Preemptive.
- Multiple queues, all with quantum 1.

### 7. FB-2i (Feedback, q=2^i)
- Preemptive.
- Multiple queues, quantum doubles at each lower priority.

### 8. Aging
- Preemptive.
- Priorities of waiting processes increase over time to prevent starvation.

---

## Extending the Project

- Add new scheduling algorithms by creating new source files in `src/` and updating the main driver.
- Add new tests in `test/` using Google Test.
- Update the makefile as needed.

---

## References

- [Operating System Concepts by Silberschatz, Galvin, Gagne](https://www.os-book.com/)
- [Wikipedia: Scheduling (computing)](https://en.wikipedia.org/wiki/Scheduling_(computing))
-