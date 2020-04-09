function string:split(delimiter)
  local result = { }
  local from  = 1
  local delim_from, delim_to = string.find( self, delimiter, from  )
  while delim_from do
    table.insert( result, string.sub( self, from , delim_from-1 ) )
    from  = delim_to + 1
    delim_from, delim_to = string.find( self, delimiter, from  )
  end
  table.insert( result, string.sub( self, from  ) )
  return result
end


function writeLog(message,path)
    local fileName = '/Users/ray/Documents/C/clua/runtxt.log'
    message = message .. '\r\n'

    local now   = os.date('%Y-%m-%d %H:%M:%S')
    message     = now ..': '..message
    local f = io.open(fileName, "a+")
    if f then
        f:write(message)
        f:close()
    end
end



--格式 dtype#a#b
function dispatch(param)
	if param then
		writeLog(param)

		local cmdArr = string.split(param, "%#")
		local funcName = cmdArr[1]
		local parm1 = (cmdArr[2])
		local parm2 = (cmdArr[3])
		print(funcName, parm1, parm2)

		local postStatus, ret = pcall(_ENV[funcName], parm1, parm2)  --调用函数
		print(ret,postStatus)  --true 3
		return ret,postStatus
	end
	return -1,"param error"
end


function addv(a,b)
	--print(a,b)
	return a+b
end


function subv(a,b)
	return a-b
end

function appendV(v)
	return v.." hello from lua"
end

function getfunc()
	local str = Getfunc()
	return str.." with lua"
end