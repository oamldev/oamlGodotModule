def can_build(platform):
  return True

def configure(env):
  if env["platform"] == "osx":
    env.Append(LINKFLAGS=['-framework','CoreAudio','-framework','CoreFoundation'])
