# UAS DESIGN

This open-source software aims to provide a starting point for UAS Design calculations.

## Software design

Language: C++

## Modules

1. Control System
   1. Classical Automatic Control Theory
   2. Modern Automatic Control Theory
1. Propulsion System
   1. Motor
   1. ESC
   1. Battery
1. System Specification
   1. calculation for combining different components

## Testing framework

TBD

# Building

## Download OpenAPI Generator

```
wget https://repo1.maven.org/maven2/org/openapitools/openapi-generator-cli/6.0.1/openapi-generator-cli-6.0.1.jar -O ~/Applications/openapi-generator-cli.jar
```

## Generate API for JS

```
cd api
make
```

## Generate JS Bundle

```
cd html/js
npm install
npm run build
./node_modules/.bin/browserify --standalone apiBundle dist/index.js > dist/bundle.js
```

## Build Backend CPP Server

Dependencies must be installed (see [this for more details](./backend-cpp/README.md)

1. `oatpp`
1. `oatpp-sqlite`
1. `oatpp-swagger`

```
cd backend-cpp
mkdir build
cd build
cmake ..
cmake --build .
```

Run Backend Server

```
cd backend-cpp
./crud-exe
```

Run Frontend Server

```
cd html
python3 serve.py
```
