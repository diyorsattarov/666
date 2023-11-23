# lcu-api-test

## Overview

This project, "lcu-api-test," is designed to facilitate interaction with League of Legends' LCU (League Client Update) API. It includes modules for authentication, utility functions, and LCU-specific functionalities.

### Project Structure

```
lcu-api-test/
|-- docs/
|-- examples/
|-- src/
|   |-- auth/
|   |   |-- auth.cpp
|   |-- lcu/          
|   |   |-- lcu.cpp
|   |-- utils/          
|   |   |-- utils.cpp
|-- include/
|   |-- auth/
|   |   |-- auth.h
|   |-- lcu/          
|   |   |-- lcu.h
|   |-- utils/          
|   |   |-- utils.h
|-- tests/
|   |-- auth/
|   |   |-- test_auth.cpp
|   |-- lcu/          
|   |   |-- test_lcu.cpp
```

## Usage

To use the functionalities provided by this project, include the necessary headers and source files in your project. Here's a quick overview:

1. **Authentication Module (auth.h / auth.cpp)**:
   - Use these files to authenticate and obtain client information.

2. **Utility Module (utils.h / utils.cpp)**:
   - Includes general-purpose utility functions that aid in various tasks.

3. **LCU Module (lcu.h / lcu.cpp)**:
   - Implementations specific to League of Legends' LCU API.

4. **Tests**:
   - The `tests/auth/test_auth.cpp` file contains tests for the authentication module.
   - The `tests/lcu/test_lcu.cpp` file includes tests for the LCU module.

## TODO List

- [ ] Implement additional LCU functionalities.
- [ ] Enhance authentication security features.
- [ ] Improve utility functions for broader use cases.

## Credits

This project is an educational endeavor, where I have gained inspiration and insights from [KBotExt by KebsCS](https://github.com/KebsCS/KBotExt). I would like to express my gratitude to KebsCS for their significant contributions to the League of Legends community, which have served as a valuable reference for this learning experience.