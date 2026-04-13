#!/bin/bash

# Ejercicio 1: crear el árbol de directorios

raiz="Materias"

mkdir -p "$raiz"/SistemasEmbebidos/Microcontroladores/{ARM,PIC}
mkdir -p "$raiz"/SistemasEmbebidos/Comunicaciones/{UART,I2C}
mkdir -p "$raiz"/SistemasEmbebidos/Perifericos/{ADC,PWM}
mkdir -p "$raiz"/VisionComputacional/{OpenCV,DeteccionObjetos}
mkdir -p "$raiz"/MachineLearning/{Supervised,Unsupervised,Reinforcement}

echo "Árbol creado correctamente."

echo
echo "Verificación con find:"
find "$raiz" -type d | sort