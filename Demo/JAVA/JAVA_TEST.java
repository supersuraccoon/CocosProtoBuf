
import java.util.ArrayList;
import java.util.List;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

import com.game.info.GameInfoProtos;
import com.game.enumeration.GameEnumProtos;

public class JAVA_TEST {

    public static void main(String[] args) {

    	List<GameInfoProtos.RoleInfo> roleInfoList = new ArrayList<GameInfoProtos.RoleInfo>();
		GameInfoProtos.RoleInfo roleInfo1 = GameInfoProtos.RoleInfo.newBuilder()
			.setName("name1")
			.setType(GameEnumProtos.RoleType.FIGHTER)
		.build();
		roleInfoList.add(roleInfo1);

		GameInfoProtos.RoleInfo roleInfo2 = GameInfoProtos.RoleInfo.newBuilder()
			.setName("name2")
			.setType(GameEnumProtos.RoleType.BOWMAN)
		.build();
		roleInfoList.add(roleInfo2);

		// build item info list
		List<GameInfoProtos.ItemInfo> itemInfoList = new ArrayList<GameInfoProtos.ItemInfo>();
		GameInfoProtos.ItemInfo itemInfo1 = GameInfoProtos.ItemInfo.newBuilder()
			.setName("item1")
			.setPrice(100)
		.build();
		itemInfoList.add(itemInfo1);

		GameInfoProtos.ItemInfo itemInfo2 = GameInfoProtos.ItemInfo.newBuilder()
			.setName("item2")
			.setPrice(200)
		.build();
		itemInfoList.add(itemInfo2);

		// build game info
		GameInfoProtos.GameInfo gameInfoOut = GameInfoProtos.GameInfo.newBuilder()
			.addAllRoleInfo(roleInfoList)
			.addAllItemInfo(itemInfoList)
		.build();
		System.out.println("gameInfoOut:\n" + gameInfoOut.toString());

		byte[] bytesOut = gameInfoOut.toByteArray();
		System.out.println("bytesOut:\n" + bytesOut);

		try {
			GameInfoProtos.GameInfo gameInfoIn = GameInfoProtos.GameInfo.parseFrom(bytesOut);
			System.out.println("\ngameInfoIn:\n" + gameInfoIn.toString());	

			for (int i = 0; i < gameInfoIn.getRoleInfoList().size(); i++) {
				GameInfoProtos.RoleInfo roleInfo = gameInfoIn.getRoleInfoList().get(i);
				System.out.println(String.format("roleInfo: %s, %d", roleInfo.getName(), roleInfo.getType().getNumber()));
			}

			for (int i = 0; i < gameInfoIn.getItemInfoList().size(); i++) {
				GameInfoProtos.ItemInfo itemInfo = gameInfoIn.getItemInfoList().get(i);
				System.out.println(String.format("itemInfo: %s, %d", itemInfo.getName(), itemInfo.getPrice()));
			}
			System.out.println();
		} catch (Exception e) {
			System.out.println(e.toString());
		} finally {}
		

		FileInputStream ofs = null;
		try {
			File file = new File("../BIN/RoleInfo.bin");
			ofs = new FileInputStream(file);
			byte[] byteArray = new byte[(int) file.length()];
			ofs.read(byteArray);
			ofs.close();

			GameInfoProtos.GameInfo gameInfo = null;
			gameInfo = GameInfoProtos.GameInfo.parseFrom(byteArray);

			for (int i = 0; i < gameInfo.getRoleInfoList().size(); i++) {
				GameInfoProtos.RoleInfo roleInfo = gameInfo.getRoleInfoList().get(i);
				System.out.println(String.format("roleInfo: %s, %d", roleInfo.getName(), roleInfo.getType().getNumber()));
			}

			//
			File file2 = new File("../BIN/ItemInfo.bin");
			ofs = new FileInputStream(file2);
			byte[] byteArray2 = new byte[(int) file2.length()];
			ofs.read(byteArray2);
			ofs.close();

			gameInfo = GameInfoProtos.GameInfo.parseFrom(byteArray2);

			System.out.println();
			for (int i = 0; i < gameInfo.getItemInfoList().size(); i++) {
				GameInfoProtos.ItemInfo itemInfo = gameInfo.getItemInfoList().get(i);
				System.out.println(String.format("itemInfo: %s, %d", itemInfo.getName(), itemInfo.getPrice()));
			}

		} catch (Exception e) {
			System.out.println(e.toString());
		} finally {
			if (ofs != null) {
				try {
					ofs.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
    }
}