//
var ProtoBuf = require("./protobuf");

var GameInfoBuilder = ProtoBuf.newBuilder();

// load .proto
ProtoBuf.loadProtoFile("../PROTO/GameInfo.proto", null, GameInfoBuilder);
ProtoBuf.loadProtoFile("../PROTO/GameEnum.proto", null, GameInfoBuilder);

var Game = GameInfoBuilder.build("game");

console.log("\n------ testCreate ------\n\n");

var gameInfoOut = new Game.info.GameInfo();

var roleInfo1 = new Game.info.RoleInfo();
roleInfo1.name = "name1";
roleInfo1.type = Game.enumeration.RoleType.FIGHTER;
gameInfoOut.roleInfo.push(roleInfo1);

var roleInfo2 = new Game.info.RoleInfo();
roleInfo2.name = "name2";
roleInfo2.type = Game.enumeration.RoleType.BOWMAN;
gameInfoOut.roleInfo.push(roleInfo2);

var itemInfo1 = new Game.info.ItemInfo();
itemInfo1.name = "item1";
itemInfo1.price = 100;
gameInfoOut.itemInfo.push(itemInfo1);

var itemInfo2 = new Game.info.ItemInfo();
itemInfo2.name = "item2";
itemInfo2.price = 200;
gameInfoOut.itemInfo.push(itemInfo2);

console.log("gameInfoOut: " + gameInfoOut);
console.log("\n------ ---------- ------\n\n");

console.log("\n------ testEncode ------\n\n");
var gameInfoData = gameInfoOut.encodeAB();
console.log("gameInfoData: " + gameInfoData);
console.log("\n------ ---------- ------\n\n");

console.log("\n------ testDecode ------\n\n");
var gameInfoIn = Game.info.GameInfo.decode(gameInfoData, "utf8");
console.log("gameInfoIn: " + gameInfoIn);
console.log("\n");	        

for (var i = 0; i < gameInfoIn.roleInfo.length; i ++) {
	var roleInfo = gameInfoIn.roleInfo[i];
	console.log("roleInfo: \nname: " + roleInfo.name + " type: " + roleInfo.name + "\n");
}
console.log("\n");

for (var i = 0; i < gameInfoIn.itemInfo.length; i ++) {
	var itemInfo = gameInfoIn.itemInfo[i];
	console.log("itemInfo: \nname: " + itemInfo.name + " price: " + itemInfo.price + "\n");
}
console.log("\n------ ---------- ------\n\n");

console.log("\n------ testLoadBin ------\n\n");
var gameInfo = new Game.info.GameInfo();
var content = ProtoBuf.Util.fetch("../BIN/RoleInfo.bin");
var gameInfo = Game.info.GameInfo.decode(content, "utf8");

for (var i = 0; i < gameInfo.roleInfo.length; i ++) {
	var roleInfo = gameInfo.roleInfo[i];
	console.log("roleInfo: \nname: " + roleInfo.name + " type: " + roleInfo.name + "\n");
}
console.log("\n");

content = ProtoBuf.Util.fetch("../BIN/ItemInfo.bin");
gameInfo = Game.info.GameInfo.decode(content, "utf8");
for (var i = 0; i < gameInfo.itemInfo.length; i ++) {
	var itemInfo = gameInfo.itemInfo[i];
	console.log("itemInfo: \nname: " + itemInfo.name + " price: " + itemInfo.price + "\n");
}
console.log("\n------ ---------- ------\n\n");
