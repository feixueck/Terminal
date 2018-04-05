/*++
Copyright (c) Microsoft Corporation

Module Name:
- adaptDispatch.hpp

Abstract:
- This serves as the Windows Console API-specific implementation of the
    callbacks from our generic Virtual Terminal Input parser.

Author(s):
- Mike Griese (migrie) 11 Oct 2017
--*/
#pragma once

#include "IInteractDispatch.hpp"
#include "conGetSet.hpp"

namespace Microsoft::Console::VirtualTerminal
{
    class InteractDispatch : public IInteractDispatch
    {
    public:

        InteractDispatch(_In_ std::unique_ptr<ConGetSet> const pConApi);

        virtual ~InteractDispatch() override = default;

        virtual bool WriteInput(_In_ std::deque<std::unique_ptr<IInputEvent>>& inputEvents) override;
        virtual bool WriteCtrlC() override;
        virtual bool WriteString(_In_reads_(cch) const wchar_t* const pws, _In_ const size_t cch) override;
        virtual bool WindowManipulation(_In_ const DispatchCommon::WindowManipulationType uiFunction,
                                        _In_reads_(cParams) const unsigned short* const rgusParams,
                                        _In_ size_t const cParams) override; // DTTERM_WindowManipulation
        virtual bool MoveCursor(_In_ const unsigned int row,
                                _In_ const unsigned int col) override;
    private:

        std::unique_ptr<ConGetSet> _pConApi;

    };
}