#!/bin/bash

read -p "¿Tu 3er recuperatorio es sobre la primera parte? (si/no): " resp
resp=${resp,,}

if [[ "$resp" == "si" || "$resp" == "s" ]]; then
    parte="1era parte"
else
    parte="2da parte"
fi

mkdir -p \
  "examen recuperatorio/1er recuperatorio/Shell_y_c++" \
  "examen recuperatorio/2do recuperatorio/python_y_progra_embebida" \
  "examen recuperatorio/3er recuperatorio/$parte"

echo "Árbol creado correctamente:"
command -v tree >/dev/null 2>&1 && tree "examen recuperatorio" || find "examen recuperatorio" -print