#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "GameInfo.pb.h"

#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/compiler/importer.h>

using namespace std;

/*
	Comliper :
	
	g++ -c -I./ GameInfo.pb.cc
	g++ -c -I./ GameEnum.pb.cc
	g++ -c -I./ CPP_TEST.cpp

	Link :
	g++ -L./ -lprotobuf GameEnum.pb.o GameInfo.pb.o CPP_TEST.o -o main

	Compiler && Run :
	g++ -I./ -L./ -lprotobuf GameInfo.pb.cc GameEnum.pb.cc CPP_TEST.cpp -o main

	Run :
	./main
*/

void dumpGameInfo(game::info::GameInfo gameInfo) 
{
	// RoleInfo Array
	for (int i = 0; i < gameInfo.roleinfo_size(); i++) {
		// role info
	    game::info::RoleInfo roleInfo = gameInfo.roleinfo(i);
	    printf("roleInfo: \n%s\n", roleInfo.Utf8DebugString().c_str());
	}

	// ItemInfo Array
	for (int i = 0; i < gameInfo.iteminfo_size(); i++) {
		// role info
	    game::info::ItemInfo itemInfo = gameInfo.iteminfo(i);
	    printf("itemInfo: \n%s\n", itemInfo.Utf8DebugString().c_str());
	}
}

// reflection
void dumpMessageReflection(const google::protobuf::Message* pMessageInfo)
{
    // Message Descriptor
    const google::protobuf::Descriptor* pDescriptor = pMessageInfo->GetDescriptor();
    const google::protobuf::Reflection* pReflection = pMessageInfo->GetReflection();
    for (int i = 0; i < pDescriptor->field_count(); i ++) {
        // FieldDescriptor
        const google::protobuf::FieldDescriptor* pMessageField = pDescriptor->field(i);
        int fieldSize = pMessageField->is_repeated() ? pReflection->FieldSize(*pMessageInfo, pMessageField) : 0;
        printf("Field: %s, type: %d, fieldSize: %d\n", pMessageField->name().c_str(), pMessageField->type(), fieldSize);

        switch(pMessageField->type()) {
			case google::protobuf::FieldDescriptor::TYPE_INT64 :
			case google::protobuf::FieldDescriptor::TYPE_UINT64 :
			case google::protobuf::FieldDescriptor::TYPE_FIXED64 :
			case google::protobuf::FieldDescriptor::TYPE_FIXED32 :
			case google::protobuf::FieldDescriptor::TYPE_BOOL :
			case google::protobuf::FieldDescriptor::TYPE_GROUP :
			case google::protobuf::FieldDescriptor::TYPE_BYTES :
			case google::protobuf::FieldDescriptor::TYPE_UINT32 :
			case google::protobuf::FieldDescriptor::TYPE_SFIXED32 :
			case google::protobuf::FieldDescriptor::TYPE_SFIXED64 :
			case google::protobuf::FieldDescriptor::TYPE_SINT32 :
			case google::protobuf::FieldDescriptor::TYPE_SINT64 :
				printf("FieldDescriptor type not handled !");
				break;
			case google::protobuf::FieldDescriptor::TYPE_INT32 :
				if (fieldSize == 0) {
					printf("Value: %d\n\n", pReflection->GetInt32(*pMessageInfo, pMessageField));
				}
				else {
					for (int j = 0; j < fieldSize; j ++) {
						printf("Value: %d\n\n", pReflection->GetRepeatedInt32(*pMessageInfo, pMessageField, j));
					}
				}
				break;
			case google::protobuf::FieldDescriptor::TYPE_FLOAT :
				if (fieldSize == 0) {
					printf("Value: %f\n\n", pReflection->GetFloat(*pMessageInfo, pMessageField));
				}
				else {
					for (int j = 0; j < fieldSize; j ++) {
						printf("Value: %f\n\n", pReflection->GetRepeatedFloat(*pMessageInfo, pMessageField, j));
					}
				}
				break;
			case google::protobuf::FieldDescriptor::TYPE_DOUBLE :
				if (fieldSize == 0) {
					printf("Value: %lf\n\n", pReflection->GetDouble(*pMessageInfo, pMessageField));
				}
				else {
					for (int j = 0; j < fieldSize; j ++) {
						printf("Value: %lf\n\n", pReflection->GetRepeatedDouble(*pMessageInfo, pMessageField, j));
					}
				}
				break;
			case google::protobuf::FieldDescriptor::TYPE_STRING :
				if (fieldSize == 0) {
					printf("Value: %s\n\n", pReflection->GetString(*pMessageInfo, pMessageField).c_str());
				}
				else {
					for (int j = 0; j < fieldSize; j ++) {
						printf("Value: %s\n\n", pReflection->GetRepeatedString(*pMessageInfo, pMessageField, j).c_str());
					}
				}
				break;
			case google::protobuf::FieldDescriptor::TYPE_ENUM :
				if (fieldSize == 0) {
					printf("Value: %d\n\n", pReflection->GetEnum(*pMessageInfo, pMessageField)->number());
				}
				else {
					for (int j = 0; j < fieldSize; j ++) {
						printf("Value: %d\n\n", pReflection->GetRepeatedEnum(*pMessageInfo, pMessageField, j)->number());
					}
				}
				break;
			case google::protobuf::FieldDescriptor::TYPE_MESSAGE :
				// recurse
				if (fieldSize == 0) {
					dumpMessageReflection(&pReflection->GetMessage(*pMessageInfo, pMessageField));
				}
				else {
					for (int j = 0; j < fieldSize; j ++) {
						dumpMessageReflection(&pReflection->GetRepeatedMessage(*pMessageInfo, pMessageField, j));
					}
				}
				break;
        	default:
        		break;
        }
    }
}

// test
game::info::GameInfo testCreate()
{
	// Create a GameInfo object first
	game::info::GameInfo gameInfo;

	// add RoleInfo object to repeated field
	game::info::RoleInfo *pRoleInfo1 = gameInfo.add_roleinfo();
	pRoleInfo1->set_name("name1");
	pRoleInfo1->set_type(game::enumeration::FIGHTER);

	// add another RoleInfo object to repeated field
	game::info::RoleInfo *pRoleInfo2 = gameInfo.add_roleinfo();
	pRoleInfo2->set_name("name2");
	pRoleInfo2->set_type(game::enumeration::BOWMAN);

	// add ItemInfo object to repeated field
	game::info::ItemInfo *pItemInfo1 = gameInfo.add_iteminfo();
	pItemInfo1->set_name("item1");
	pItemInfo1->set_price(100);

	// add another ItemInfo object to repeated field
	game::info::ItemInfo *pItemInfo2 = gameInfo.add_iteminfo();
	pItemInfo2->set_name("item2");
	pItemInfo2->set_price(200);

	return gameInfo;
} 


std::string testSerializeToString(game::info::GameInfo gameInfo) 
{
	std::string gameInfoString;
	gameInfo.SerializeToString(&gameInfoString);
	return gameInfoString;
}

void testSerializeToFile(game::info::GameInfo gameInfo) 
{
	ofstream outputFile("GameInfo.bin", std::ostream::binary);
	gameInfo.SerializeToOstream(&outputFile);
	outputFile.close();
}

game::info::GameInfo testParseFromString(std::string gameInfoString) 
{
	game::info::GameInfo gameInfo;
	// parse string
	gameInfo.ParseFromString(gameInfoString);
	return gameInfo;
}

game::info::GameInfo testParseFromFile(std::string fileName) 
{
	game::info::GameInfo gameInfo;
	// parse from bin
	ifstream is(fileName.c_str(), std::ifstream::binary);
	gameInfo.ParseFromIstream(&is);
	is.close();
	return gameInfo;
}

void testDynamicGenerate()
{
	google::protobuf::compiler::DiskSourceTree sourceTree;
    sourceTree.MapPath("", "./proto");
    google::protobuf::compiler::Importer importer(&sourceTree, NULL);
    importer.Import("GameEnum.proto");
    importer.Import("GameInfo.proto");
 
 	google::protobuf::DynamicMessageFactory factory;
    const google::protobuf::Descriptor* pDescriptorDynamic = NULL;
    const google::protobuf::Reflection* pReflectionDynamic = NULL;
    const google::protobuf::FieldDescriptor* pFieldDynamic = NULL;
    const google::protobuf::EnumDescriptor* pEnumDescriptorDynamic = NULL;
    google::protobuf::Message* pGameInfoDynamic = NULL;
    google::protobuf::Message* pRoleInfoDynamic = NULL;
    google::protobuf::Message* pItemInfoDynamic = NULL;
    
    // create a instance of GameInfo
    pDescriptorDynamic = importer.pool()->FindMessageTypeByName("game.info.GameInfo");
    // printf("%s", pDescriptorDynamic->DebugString().c_str());
    pGameInfoDynamic = factory.GetPrototype(pDescriptorDynamic)->New();
    pReflectionDynamic = pGameInfoDynamic->GetReflection();

    // get repeated roleinfo instance
    pFieldDynamic = pDescriptorDynamic->FindFieldByName("roleInfo");
    pRoleInfoDynamic = pReflectionDynamic->AddMessage(pGameInfoDynamic, pFieldDynamic);

    // set string filed name
    pDescriptorDynamic = importer.pool()->FindMessageTypeByName("game.info.RoleInfo");
    pEnumDescriptorDynamic = importer.pool()->FindEnumTypeByName("game.enumeration.RoleType");
    pFieldDynamic = pDescriptorDynamic->FindFieldByName("name");
    pRoleInfoDynamic->GetReflection()->SetString(pRoleInfoDynamic, pFieldDynamic, "role_name_dynamic1");
    // set enum filed type
    pFieldDynamic = pDescriptorDynamic->FindFieldByName("type");
    pRoleInfoDynamic->GetReflection()->SetEnum(pRoleInfoDynamic, pFieldDynamic, pEnumDescriptorDynamic->FindValueByName("MAGICIAN"));


	// get repeated iteminfo instance
	pDescriptorDynamic = importer.pool()->FindMessageTypeByName("game.info.GameInfo");
    pFieldDynamic = pDescriptorDynamic->FindFieldByName("itemInfo");
    pItemInfoDynamic = pReflectionDynamic->AddMessage(pGameInfoDynamic, pFieldDynamic);

    // set string filed name
    pDescriptorDynamic = importer.pool()->FindMessageTypeByName("game.info.ItemInfo");
    pFieldDynamic = pDescriptorDynamic->FindFieldByName("name");
    pItemInfoDynamic->GetReflection()->SetString(pItemInfoDynamic, pFieldDynamic, "item_name_dynamic1");
    // set int32 filed type
    pFieldDynamic = pDescriptorDynamic->FindFieldByName("price");
    pItemInfoDynamic->GetReflection()->SetInt32(pItemInfoDynamic, pFieldDynamic, 999999);

    dumpMessageReflection(pGameInfoDynamic);
}


int main() 
{	
	printf("\n------ testCreate ------\n\n");
	game::info::GameInfo gameInfo = testCreate();
	printf("dumpGameInfo:\n");
	dumpGameInfo(gameInfo);
	printf("------ ---------- ------\n\n");


	printf("------ testSerializeToString ------\n\n");
	std::string gameInfoString = testSerializeToString(gameInfo);
	printf("------ ---------- ------\n\n");


	printf("------ testSerializeToFile ------\n\n");
	testSerializeToFile(gameInfo);
	printf("------ ---------- ------\n\n");


	printf("------ testParseFromString ------\n\n");
	game::info::GameInfo gameInfoFromString = testParseFromString(gameInfoString);
	dumpGameInfo(gameInfoFromString);
	
	printf("------ ---------- ------\n\n");

	printf("------ testParseFromFile ------\n\n");
	game::info::GameInfo gameInfoFromFile = testParseFromFile("GameInfo.bin");
	dumpGameInfo(gameInfoFromFile);
	printf("------ ---------- ------\n\n");


	printf("------ dumpMessageReflection RoleInfo ------\n\n");
	game::info::RoleInfo roleInfoReflect;
	roleInfoReflect.set_name("name_reflect");
	roleInfoReflect.set_type(game::enumeration::FIGHTER);
	dumpMessageReflection(&roleInfoReflect);
	printf("------ ---------- ------\n\n");

	
	printf("------ dumpMessageReflection GameInfo ------\n\n");
   	dumpMessageReflection(&gameInfo);
	printf("------ ---------- ------\n\n");

	
	printf("------ testDynamicGenerate ------\n\n");
	testDynamicGenerate();
    printf("------ ---------- ------\n\n");
}

