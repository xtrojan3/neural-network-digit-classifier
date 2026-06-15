# Neural Network Digit Classifier

A single-layer neural network for classifying handwritten digits (0–9) from the MNIST dataset, written in C from scratch.

## How it works

The program reads a handwritten digit image (28×28 pixels = 784 values) from stdin and classifies it using a pre-trained neural network.

```
Input image (784 pixels)
        ↓
Weighted sum + bias (per neuron)
        ↓
ReLU activation
        ↓
Softmax → probability distribution
        ↓
argmax → predicted digit (0–9)
```

Pre-trained weights and biases are stored in `data.h`.

## Build

```bash
gcc -o classifier main.c -lm
```

## Usage

The program reads a **mode number** from stdin, then additional input depending on the mode.

```bash
./classifier
```

| Mode | Description | Input |
|------|-------------|-------|
| 1 | Print weights of a neuron | neuron index |
| 2 | Compute weighted sum for a neuron | neuron index + image pixels |
| 3 | Apply ReLU to a value | one float |
| 4 | Apply Softmax to raw outputs | 10 floats |
| 5 | Find index of max value (argmax) | 10 floats |
| 6 | Load and print image as ASCII | image pixels |
| 7 | Full classification of an image | image pixels |

## Examples

```bash
# Classify a digit image (mode 7)
./classifier < stdin/mode07/digit_7.txt
# → 7

# Print weights of neuron 3 (mode 1)
echo "1 3" | ./classifier

# Apply softmax to 10 raw scores (mode 4)
echo "4
1.0 2.0 0.5 -1.0 3.0 0.0 1.5 2.5 -0.5 0.1" | ./classifier
```

## Test data

The `stdin/` folder contains ready-to-use input files for each mode:

```bash
./classifier < stdin/mode07/sample.txt
```

The `digits-txt/` folder contains digit images as text files (784 pixel values in range 0–1).  
The `digits-img/` folder contains the same digits as visual image files.

## Python scripts

Two helper scripts are included for experimentation:

- `img2txt.py` — converts a grayscale image to text format (pixel values 0–1)
- `txt2img.py` — converts a text file back to a visual image

```bash
python python_scripts/img2txt.py my_digit.png
python python_scripts/txt2img.py digits-txt/digit_7.txt
```

## File structure

```
.
├── main.c          # mode dispatcher + core logic
├── functions.h     # declarations for relu(), load_data(), print_image()
├── data.h          # pre-trained weights and biases
├── digits-txt/     # digit images as text files (pixel values)
├── digits-img/     # digit images as PNG files
├── python_scripts/ # helper scripts for image conversion
└── stdin/          # test input files for each mode (mode01–mode07)
```

## Dataset

Based on the [MNIST database](https://en.wikipedia.org/wiki/MNIST_database) — 60,000 training and 10,000 test images of handwritten digits.  
Pixel values are normalized from [0, 255] to [0, 1].

Inspired by [Andrew Carter's MNIST Neural Network in C](https://github.com/AndrewCarterUK/mnist-neural-network-plain-c).
