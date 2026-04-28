# Deterministic Simulation Demo

## Overview

A small C++ console demo showing fixed-timestep simulation, deterministic update ordering, and structured event logging.

## Purpose

This project demonstrates core concepts used in simulation software: reproducible execution, controlled state updates, and traceable event output.

## Key Concepts

- Fixed timestep execution
- Deterministic update order
- Structured event logging
- Simple entity interaction
- Reproducible simulation output

## How It Works

The simulation advances in fixed steps. Entities update in a consistent order, interactions are evaluated deterministically, and events are recorded in a log for later inspection.

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Example Output
```
Step 0 | Attacker Position: 0.05 | Target Position: 0.975
Step 1 | Attacker Position: 0.1 | Target Position: 0.95
...
Step 19 | Attacker Position: 1 | Target Position: 0.5
```

### Event Log
```
Step 10: Attacker interacted with Target
Step 11: Attacker interacted with Target
Step 12: Attacker interacted with Target
Step 13: Attacker interacted with Target
Step 14: Attacker interacted with Target
Step 15: Attacker interacted with Target
```
