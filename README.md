# 🧠 Neural Network Digit Classifier (C)

A single-layer neural network for image classification written in C. Uses pre-trained weights and biases to classify images (e.g. handwritten digits) via a weighted sum → ReLU → softmax pipeline.

---

## Architecture

```
Input image (IMAGE_SIZE pixels)
        ↓
Weighted sum + bias  (per neuron)
        ↓
ReLU activation
        ↓
Softmax → probability distribution
        ↓
argmax → predicted class
```

Pre-trained weights and biases are loaded from `data.h`. Helper functions (`relu`, `load_data`, `print_image`) are declared in `functions.h`.

---

## Build

Requires a C11-compatible compiler and the math library.

```bash
gcc -o classifier main.c -lm
```

---

## Usage

The program reads a **mode number** from stdin, then additional input depending on the mode.

```
./classifier
```

### Modes

| Mode | Description | Additional input |
|------|-------------|-----------------|
| `1` | Print weights of a neuron as a 10-column grid | neuron index |
| `2` | Compute weighted sum for a neuron on an image | neuron index, then image pixels |
| `3` | Apply ReLU to a single value | one float |
| `4` | Apply softmax to a vector of raw outputs | NUMBER_OF_NEURONS floats |
| `5` | Find the index of the maximum value (argmax) | NUMBER_OF_NEURONS floats |
| `6` | Load and print an image as ASCII | image pixels |
| `7` | Full inference: load image → classify → print predicted class | image pixels |

---

## Examples

```bash
# Print weights of neuron 3
echo "1 3" | ./classifier

# Run full classification on an image (pixels provided via stdin)
(echo 7; cat image_pixels.txt) | ./classifier
# → 7

# Apply softmax to 10 raw scores
echo "4
1.0 2.0 0.5 -1.0 3.0 0.0 1.5 2.5 -0.5 0.1" | ./classifier
# → 0.02 0.06 0.01 0.00 0.16 0.01 0.03 0.09 0.01 0.01
```

---

## File structure

```
.
├── main.c        # mode dispatcher + core functions (weightedSum, softMax, findMax)
├── functions.h   # declarations for relu(), load_data(), print_image()
└── data.h        # pre-trained weights[] and bias[] arrays
```

---

## Notes

- Softmax uses the **max-subtraction trick** for numerical stability
- Mode `7` is the full end-to-end inference pipeline
- `IMAGE_SIZE`, `IMAGE_WIDTH`, `IMAGE_HEIGHT`, and `NUMBER_OF_NEURONS` are defined as macros (likely in `data.h` or `functions.h`)
