# CSE221 Benchmark

# PreReqs

Env management using nix: https://nixos.org

type `nix-shell` from the project root to enter dev env

## Commands

Checkout the makefile for more info. **Some section may contain special instruction located in its own `README.md` please check them out before continue.**

### Standard workflow

```bash
make clean # Clear all file
make all # all target
make run_test # run test
```

- Result json will be placed in dist, suffix with run unix timestamp
- Affinity by default set to a single core (core 30 in our script)
