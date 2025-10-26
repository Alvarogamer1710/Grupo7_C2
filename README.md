# 📘 Proyecto AC2 - Sistema de Gestión para un Centro de Formación Profesional

## 🏫 Universidad Europea de Madrid
**Grado en Ingeniería Informática — 2º Curso**

**Autores:**
- Álvaro Hernández
- Juan Labajo
- Esteban Damián Laguinge
- Iván Sanz López

---

## 📖 Introducción

Este proyecto forma parte de la **Actividad Colaborativa 2 (AC2)** de la asignatura correspondiente a la Unidad Formativa en la que se evalúan las competencias adquiridas en programación orientada a objetos y gestión de estructuras de datos.

El objetivo principal es desarrollar una **aplicación de gestión de datos para un centro de formación profesional**, que permita a diferentes tipos de usuarios (administradores, profesores y estudiantes) interactuar con el sistema de acuerdo con sus roles y funcionalidades específicas.

---

## 🧩 Objetivos del Proyecto

- Poner en práctica los conocimientos adquiridos sobre **estructuras de datos, clases, objetos, y modularización del código**.
- Desarrollar una aplicación funcional que gestione usuarios, datos académicos y recursos digitales.
- Aplicar conceptos de **persistencia, control de acceso y encapsulación**.
- Incorporar funcionalidades de utilidad general (como una calculadora avanzada y un minijuego interactivo).

---

## ⚙️ Requisitos Funcionales

### **1️⃣ Gestión de Estudiantes por Aula**
- Los **profesores** pueden:
    - Crear y visualizar su lista de estudiantes.
    - Consultar datos personales de los alumnos: nombre, apellidos y notas por asignatura.
    - Ver el número de alumnos inscritos en su clase.
- Cada profesor solo puede tener **una clase asignada**, y cada alumno solo puede pertenecer a un profesor.

---

### **2️⃣ Mochila Digital del Estudiante**
- Los **estudiantes** pueden:
    - Cargar en su “mochila” archivos `.txt` con información o actividades realizadas.
    - Visualizar el contenido de los archivos cargados dentro de la aplicación.
    - Gestionar varios ficheros simultáneamente.

---

### **3️⃣ Calculadora Avanzada**
- Funciones básicas: suma, resta, multiplicación y división.
- Operaciones con **matrices de tamaño n×n**, incluyendo:
    - Suma, resta, multiplicación y división de matrices.
    - *(Opcional)* Cálculo de la **matriz traspuesta**.
    - *(Opcional)* Cálculo del **determinante** si la matriz es cuadrada.

---

### **4️⃣ Sistema de Gestión de Usuarios (Altas y Bajas)**
- El **administrador** puede:
    - Dar de alta o baja a usuarios del sistema.
    - Gestionar su información personal (nombre, apellido, número de usuario).
    - Asignar un **ID único** a cada usuario.
    - Eliminar completamente los datos de un usuario dado de baja.

---

### **5️⃣ Juego: “Adivina el Número”**
- El sistema genera un número aleatorio entre 1 y 100.
- El usuario debe adivinarlo introduciendo valores.
- El programa indica si el número buscado es **mayor o menor** que el introducido.
- Al acertar, muestra el **número de intentos realizados**.

---

## 🧠 Arquitectura del Sistema

El proyecto sigue un enfoque **modular y orientado a objetos**, donde cada recurso se implementa como un módulo o clase independiente.
- **Clases principales:** `Usuario`, `Profesor`, `Estudiante`, `Administrador`, `Calculadora`, `Juego`, `Mochila`, `Documento`, etc.
- **Control principal:** un menú interactivo que permite acceder a las funcionalidades según el rol del usuario.
- **Estructuras de datos:** listas, diccionarios o arrays según la necesidad del recurso.

---

## 🖥️ Tecnologías Utilizadas

- **Lenguaje:** Python 3 (o el lenguaje especificado por la unidad formativa).
- **Paradigma:** Programación Orientada a Objetos.
- **Gestión de archivos:** lectura y escritura de ficheros `.txt`.
- **Control de flujo:** estructuras condicionales y bucles.
- **Módulos personalizados:** para cada funcionalidad principal.

---

## 🚀 Instrucciones de Ejecución

1. Clonar o descargar el repositorio.
   ```bash
   git clone https://github.com/usuario/proyecto-ac2.git
