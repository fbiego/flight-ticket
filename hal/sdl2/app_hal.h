#ifndef DRIVER_H
#define DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif


void hal_setup(void);
void hal_loop(void);

void set_window_title(const char *title);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*DRIVER_H*/
