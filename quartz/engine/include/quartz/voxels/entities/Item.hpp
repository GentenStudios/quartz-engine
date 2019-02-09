#pragma once

#include <quartz/core/Core.hpp>

#include <string>
#include <vector>

namespace qz
{
	namespace entities
	{
		class Item
		{
		public:
			/**
			 * @brief Initialise an item
			 * @param The unique id for the item, should be in format mod:id to eliminate conflict
			 * @param The player friendly name of the item
			 */
			Item(std::string id, std::string name);
			~Item();

			/**
			 * @brief getID - getID of Item
			 * @return Return a string for the ID of the item
			 */
			std::string getID();

			/**
			 * @brief getName - Get user friendly name of item
			 * @return Return a string of the name of the item
			 */
			std::string getName();

			/// @brief Setter: Sets the function executed when an items breaks (damage used up)
			void setOnBreakCallback(void* callback);
			/// @brief Getter: Gets the function executed when an item breaks (damage used up)
			void* getOnBreakCallback();

			/// @brief Setter: Sets the function executed when you use the item
			void setOnUseCallback(void* callback);
			/// @brief Getter: Gets the function executed when you use the item
			void* getOnUseCallback();

		private:
			/// @brief Unique id using the convention mod:name
			std::string m_id;
			/// @brief Name that will display to the user
			std::string m_name;

			/// @brief Lambda callback for when the item is broken (well, hopefully lambdas if we can)
			void* m_onBreakCallback;
			/// @brief Lambda callback for when the item is used (well, hopefully lambdas if we can)
			void* m_onUseCallback;
		};

		class ItemLibrary
		{
		public:
			/**
			 * @brief getItemByID - Get an item object based off its unique ID
			 * @param The unique ID of the item you are trying to find
			 * @return Returns an item matching the supplied ID
			 */
			static Item getItemByID(std::string id);

			static void registerItem(Item* item);

		private:
			// A registry to keep track of all the registered items
			static std::vector<Item*> m_itemLibrary;
		};
	}
}