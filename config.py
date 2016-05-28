def can_build(platform):
  return True

def configure(env):
  if env["platform"] == "windows":
    env.Append(CPPFLAGS=['-D__WINDOWS_DS__'])
  elif env["platform"] == "osx":
    env.Append(CPPFLAGS=['-D__MACOSX_CORE__'])
    env.Append(LINKFLAGS=['-framework','CoreAudio','-framework','CoreFoundation'])
  elif env["platform"] == "linux":
    env.Append(CPPFLAGS=['-D__LINUX_ALSA__'])
