# Juego Búsqueda Binario

Un juego estratégico de dos jugadores implementado en C++ donde cada jugador intenta encontrar y capturar los tesoros del oponente utilizando espías.

## Requisitos previos

- **GCC/G++** (compilador C++)
- **Make** (para usar el Makefile, opcional)
- Linux/Unix o Windows con WSL

Verificar la instalación:
```bash
g++ --version
make --version
```

## Compilación

### Opción 1: Usar el Makefile (recomendado)

```bash
make -C Debug
```

Esto genera el ejecutable `Debug/tp_0`.

### Opción 2: Compilar directamente con g++

```bash
mkdir -p bin
g++ -g src/*.cpp -o bin/principal
```

Esto genera el ejecutable `bin/principal`.

### Limpiar archivos compilados

```bash
make -C Debug clean
```

## Ejecución

Después de compilar, ejecuta el juego:

```bash
./Debug/tp_0
```

O si compilaste con la opción 2:

```bash
./bin/principal
```

## Cómo jugar

1. **Inicio del juego**: Se muestra un tablero de 20×20 para cada jugador.

2. **Turno 1 - Colocar tesoros**:
   - Cada jugador ingresa **4 tesoros** en el tablero.
   - Se solicita FILA (1-20) y COLUMNA (1-20) para cada tesoro.

3. **Turnos posteriores - Enviar espías**:
   - Cada jugador envía **espías** para buscar tesoros enemigos.
   - Opcionalmente, puede mover sus propios tesoros.

4. **Mecánica de juego**:
   - `[T]` = Tesoro
   - `[S]` = Espía
   - `[X]` = Tesoro siendo capturado
   - `[ ]` = Casilla vacía

5. **Captura de tesoros**:
   - Si un espía encuentra un tesoro enemigo, comienza la captura.
   - Después de 4 turnos, el tesoro es recuperado.
   - Si dos espías se encuentran en la misma posición, ambos se eliminan.

6. **Victoria**:
   - El jugador que recupere todos los tesoros del oponente gana.

## Archivos generados

Durante la partida se crean:
- `Tablero_Jugador1.txt` - Estado del tablero del Jugador 1
- `Tablero_Jugador2.txt` - Estado del tablero del Jugador 2

## Configuración del juego

Las constantes del juego se encuentran en `src/constantes.h`:
- `MAXIMAS_FILAS` = 20 (tamaño del tablero)
- `MAXIMAS_COLUMNAS` = 20 (tamaño del tablero)
- `TESOROS` = 4 (tesoros por jugador)
- `CANTIDAD_DE_JUGADORES` = 2
- `TURNOS_DE_RECUPERACION` = 4 (turnos para capturar un tesoro)

Puedes modificar estas constantes y recompilar para cambiar la dificultad o el tamaño del juego.

## Estructura del proyecto

```
TP1/
├── src/
│   ├── principal.cpp        # Punto de entrada del programa
│   ├── juego.cpp           # Lógica del juego
│   ├── jugadores.cpp       # Gestión de jugadores
│   ├── tablero.cpp         # Funciones del tablero
│   ├── interacciones.cpp   # Entrada/salida con el usuario
│   ├── *.h                 # Headers correspondientes
│   └── constantes.h        # Configuración del juego
├── Debug/
│   └── makefile            # Archivo de construcción
├── README.md               # Este archivo
└── Tablero_Jugador*.txt    # Archivos de estado (generados)
```

## Solución de problemas

### Error: "command not found"
Asegúrate de:
1. Estar en el directorio correcto del proyecto
2. Haber compilado antes de ejecutar
3. Usar la ruta correcta: `./Debug/tp_0` o `./bin/principal`

### Error: "Permiso denegado"
```bash
chmod +x Debug/tp_0
chmod +x bin/principal
```

### El programa se cuelga esperando entrada
Ingresa las coordenadas (FILA y COLUMNA) cuando lo solicite. Formato: números entre 1-20 seguidos de Enter.

## Licencia

Proyecto académico - Algoritmos 2

## Autor

Joani Alejandro Pranteda - Algoritmos II

