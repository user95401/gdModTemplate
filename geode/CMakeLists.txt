cmake_minimum_required(VERSION 3.10.0)
configure_file(mod.json ${CMAKE_CURRENT_BINARY_DIR}/../mod.json)
configure_file(about.md ${CMAKE_CURRENT_BINARY_DIR}/../about.md)
configure_file(changelog.md ${CMAKE_CURRENT_BINARY_DIR}/../changelog.md)
if(EXISTS ${LIBRARY_OUTPUT_PATH}/${PROJECT_NAME}.dll)
    file(COPY 
    logo.png
    ${LIBRARY_OUTPUT_PATH}/${PROJECT_NAME}.dll
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../)

    file(COPY Resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../)
    file(COPY ${LIBRARY_OUTPUT_PATH}/${PROJECT_NAME}.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../)
    file(RENAME ${CMAKE_CURRENT_BINARY_DIR}/../${PROJECT_NAME}.dll ${CMAKE_CURRENT_BINARY_DIR}/../${developer}.${PROJECT_NAME}.dll)

    file(ARCHIVE_CREATE
        OUTPUT "${CMAKE_CURRENT_LIST_DIR}/release/${developer}.${PROJECT_NAME}.geode"
        PATHS 
        ${CMAKE_CURRENT_BINARY_DIR}/../about.md
        ${CMAKE_CURRENT_BINARY_DIR}/../changelog.md
        ${CMAKE_CURRENT_BINARY_DIR}/../mod.json
        logo.png
        Resources
        ${developer}.${PROJECT_NAME}.dll
        FORMAT "zip")

    file(COPY "${CMAKE_CURRENT_LIST_DIR}/release/${developer}.${PROJECT_NAME}.geode" DESTINATION 
    ${GEODE_MOD_OUTPUT_PATH})

    message("geode makeup done: see at ${GEODE_MOD_OUTPUT_PATH} or ${CMAKE_CURRENT_LIST_DIR}/release/${developer}.${PROJECT_NAME}.geode")
else()
    message("geode makeup failed: ${LIBRARY_OUTPUT_PATH}/${PROJECT_NAME}.dll isnt exists yet.")
endif()