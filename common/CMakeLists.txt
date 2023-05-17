set(app_src keypad.c Fingerprint.c)
set(pri_req)
idf_component_register(SRCS ${app_src}
                       INCLUDE_DIRS "include"
                       REQUIRES ${pri_req})