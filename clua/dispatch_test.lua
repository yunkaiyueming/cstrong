

APP_PATH=debug.getinfo(1).short_src
APP_PATH=string.sub(APP_PATH, 0, -8)
package.path = APP_PATH.."/?.lua;" .. package.path

require "dispatch"
local param = "addv#1#2"
dispatch(param)

local param = "subv#1#2"
dispatch(param)

local param = "appendV#1#2"
dispatch(param)