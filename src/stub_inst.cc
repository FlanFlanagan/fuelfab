#include "stub_inst.h"

using stubs::StubInst;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
StubInst::StubInst(cyclus::Context* ctx)
    : cyclus::Institution(ctx) {};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
StubInst::~StubInst() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void StubInst::InfileToDb(cyclus::InfileTree* qe, cyclus::DbInit di) {
  Agent::InfileToDb(qe, di);
  qe = qe->SubTree(spec());
  // retrieve input data members here. For example:
  //
  //   int cycle_len = lexical_cast<int>(input->getElementContent("cycle_length"));
  //   ...
  //   di.NewDatum("StubFacilityParams")
  //     ->AddVal("cycle_length", cycle_len)
  //     ...
  //     ->Record();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
cyclus::Agent* StubInst::Clone() {
  StubInst* m = new StubInst(context());
  m->InitFrom(this);
  return m;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void StubInst::InitFrom(StubInst* m) {
  cyclus::Institution::InitFrom(m);
  // Initialize stubinst members for a cloned module here
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
std::string StubInst::str() {
  return Institution::str();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
extern "C" cyclus::Agent* ConstructStubInst(cyclus::Context* ctx) {
  return new StubInst(ctx);
}

// required to get functionality in cyclus agent unit tests library
#ifndef CYCLUS_AGENT_TESTS_CONNECTED
int ConnectAgentTests();
static int cyclus_agent_tests_connected = ConnectAgentTests();
#define CYCLUS_AGENT_TESTS_CONNECTED cyclus_agent_tests_connected
#endif // CYCLUS_AGENT_TESTS_CONNECTED
