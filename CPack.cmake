IF (WIN32 AND NOT UNIX)
  INCLUDE(WIN32.cpack)
ENDIF (WIN32 AND NOT UNIX)

IF (APPLE)

ENDIF (APPLE)

IF (UNIX AND NOT APPLE)

ENDIF (UNIX AND NOT APPLE)
