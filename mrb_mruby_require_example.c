// WINDOWS:
//  gcc -Ic:/path/to/mruby/include -shared -o mrb_mruby_require_example.dll \
//    mrb_mruby_require_example.c \
//    /path/to/mruby/build/host/lib/libmruby_core.a -lm 
// UNIX:
//  gcc -I/path/to/mruby/include -shared -o libmrb_mruby_require_example.so \
//    mrb_mruby_require_example.c -rdynamic \
//    /path/to/mruby/build/host/lib/libmruby_core.a -lm 
//
#include <mruby.h>
#include <mruby/string.h>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

/*
void
mrb_init_mrblib(mrb_state *mrb) {
}

void
mrb_init_mrbgems(mrb_state* mrb) {
}
*/

static struct RClass *_class_example;

static mrb_value
mrb_example_helloworld(mrb_state *mrb, mrb_value self) {
  return mrb_str_new_cstr(mrb, "こんにちわ世界");
}

void EXPORT
mrb_mruby_require_example_gem_init(mrb_state* mrb) {
  int ai = mrb_gc_arena_save(mrb);
  _class_example = mrb_define_module(mrb, "Example");
  mrb_define_class_method(mrb, _class_example, "helloworld", mrb_example_helloworld, ARGS_NONE());
  mrb_gc_arena_restore(mrb, ai);
}

/* vim:set et ts=2 sts=2 sw=2 tw=0: */
