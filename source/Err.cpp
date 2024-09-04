#include <Err.h>

using namespace cid;

cid::Err::Err(const std::string& message_, ObjectType offObjType_, void* objData_, OffendingParameterBundleType offParamBundleType_)
	: message{}
{
	loadString(parseObjData(offObjType_, objData_, offParamBundleType_));
}

ParamBundleVariant cid::Err::parseObjData(ObjectType offObjType_, void* objData_, OffendingParameterBundleType offParamBundleType_)
{
	return ParamBundleVariant();
}

void cid::Err::loadString(ParamBundleVariant bundle_)
{
	message = "This is an error";
}

void cid::Err::render()
{
	std::cout << message << std::endl;
}
