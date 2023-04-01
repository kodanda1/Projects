Meters = 5.0292
Furlongs = 0.025
Miles= 0.00312501
Foot = 16.5
Hour = 1


rods_str = float(input("Input rods: "))
print('You input',rods_str,'rods.')
rods_flt = float(rods_str)
print("\nConversions")



print("Meters:",round(rods_flt * Meters,3))
print("Feet:",round(rods_flt * Foot,3))
print("Miles:",round(rods_flt * Miles,3))
print("Furlongs:",round(rods_flt*Furlongs,3))
print("Minutes to walk",rods_flt, "rods:",round(rods_flt*60*Miles/3.1,3))
