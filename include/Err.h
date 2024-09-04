#pragma once
#include <string>
#include <iostream>
#include <variant>
#include <iostream>
#include <offending_param_bundles.h>
#include <object_types.h>

namespace cid
{


	class Err
	{
		std::string message;

	public:
		Err(const std::string& message_, ObjectType offObjType_, void* objData_, OffendingParameterBundleType offParamBundleType_);
		ParamBundleVariant parseObjData(ObjectType offObjType_, void* objData_, OffendingParameterBundleType offParamBundleType_);
		void loadString(ParamBundleVariant bundle_);
		void render();

		
	};
}