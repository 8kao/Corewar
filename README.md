# 💥 Corewar – Epitech Project

Corewar is a legendary programming game developed as part of the Epitech curriculum. It simulates a virtual battle between several programs (called "champions") loaded into a shared memory arena. The goal is to survive the longest by executing custom instructions and eliminating opponents.

---

## 🧠 Game Concept

Inspired by the original *Core War* game from the 1980s, this project features an arena where programs written in a custom assembly language compete. Each champion is loaded into a circular memory space, and a virtual machine (VM) runs the instructions of each process in a round-robin fashion. The last program still alive wins the game.

---

## 💡 Usage

./corewar [-dump nbr_cycle] [-n prog_number] [-a load_address] [prog_name.cor] ...

-dump nbr_cycle dumps the memory after the nbr_cycle execution (if the round isn't
already over) with the following format: 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)

-n prog_number sets the next program's number. By default, the first free number in the
parameter order

-a load_address sets the next program's loading address. When no address is specified,
optimize the addresses so that the processes are as far away from each other as
possible. The addresses are MEM_SIZE modulo.

## 📁 Project Structure

```corewar/
├── champions/ # Assembler: compiles .s source files into .cor binaries
├── vm/ # Virtual Machine: runs compiled .cor programs
├── include/ # Header files
├── src/
  ├── execute_instructs/ # Executes each custom instruction
  ├── lib/ # Personnal library
  ├── parser/ # Parses .cor files
  ├── vm/ # Virtual Machine: runs compiled .cor programs
├── Makefile # Build system
└── README.md # This documentation file```


