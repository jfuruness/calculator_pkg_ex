from __future__ import annotations
from .calculator import Calculator
from ._core import __version__, CPPFileCalculator
from ._core import __doc__ as _core_doc

__all__ = ["Calculator", "CPPFileCalculator", "__version__"]
__doc__ = _core_doc
