#!/bin/bash

# Crear estructura de directorios
mkdir -p proyecto/{src,bin,docs,logs}

# Verificar creación
echo "Verificando estructura..."
tree proyecto 2>/dev/null || ls -R proyecto